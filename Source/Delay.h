/*
  ==============================================================================

    Delay.h
    Created: 4 Feb 2021 10:56:12pm
    Author:  Nicholas Morgan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class Delay {
public:
    
    void process(AudioSampleBuffer& buffer, int numChannels, double sampleRate){
        for (int channel = 0; channel < numChannels; ++channel)
        {
            writeToDelayBuffer(buffer, channel);
            readFromDelayBuffer(buffer, channel, sampleRate);
            feedbackDelay(buffer, channel);
        }
        updateWriteposition(buffer.getNumSamples());
    }
    
    void writeToDelayBuffer(AudioSampleBuffer& buffer, int channel){
        
        if(delayBuffer.getNumSamples() >= buffer.getNumSamples() + writePosition) {
            delayBuffer.copyFrom(channel, writePosition, buffer.getReadPointer(channel), buffer.getNumSamples(), wet);
        }else{

            const int bufferRemaining = delayBuffer.getNumSamples() - writePosition;
            delayBuffer.copyFrom(channel, writePosition, buffer.getReadPointer(channel), bufferRemaining, wet);
            delayBuffer.copyFrom(channel, 0, buffer.getReadPointer(channel, bufferRemaining), buffer.getNumSamples() - bufferRemaining, wet);
        }
    }

    void readFromDelayBuffer(AudioSampleBuffer& buffer,int channel, double sampleRate){
        
        const int readPosition = static_cast<int> (delayBuffer.getNumSamples() + writePosition - (sampleRate * delayTime / 1000)) % delayBuffer.getNumSamples() ;
        
        if(delayBuffer.getNumSamples() >= buffer.getNumSamples() + readPosition){
            buffer.addFrom(channel, 0, delayBuffer.getReadPointer(channel, readPosition), buffer.getNumSamples());
        } else{
            const int bufferRemaining = delayBuffer.getNumSamples() - readPosition;
            buffer.addFrom(channel, 0, delayBuffer.getReadPointer(channel, readPosition), bufferRemaining);
            buffer.addFrom(channel, bufferRemaining, delayBuffer.getReadPointer(channel), buffer.getNumSamples() - bufferRemaining);
        }
    }

    void feedbackDelay(AudioSampleBuffer& buffer, int channel){

        if(delayBuffer.getNumSamples() >= buffer.getNumSamples() + writePosition){
            delayBuffer.addFrom(channel, writePosition, buffer.getReadPointer(channel), buffer.getNumSamples(), wet);
        } else{
            const int bufferRemaining = delayBuffer.getNumSamples() - writePosition;
            
            delayBuffer.addFrom(channel, bufferRemaining, buffer.getReadPointer(channel), bufferRemaining, wet);
            delayBuffer.addFrom(channel, 0, buffer.getReadPointer(channel), buffer.getNumSamples() - bufferRemaining, wet);
        }
    }
    
    void setSize(int newNumChannels, int newNumSamples){
        delayBuffer.setSize(newNumChannels, newNumSamples);
    }
    
    void updateWriteposition(int bufferLength){
        writePosition += bufferLength;
        writePosition %= delayBuffer.getNumSamples();
    }
    
    void setDelayTime(double bpm, int ratio){
        delayTime = static_cast<int>(60 / bpm * 1000 / ratio);
    }
    
    void setDelayWet(float wetLevel){
        wet = wetLevel;
    }
        
private:
    AudioBuffer<float> delayBuffer;
    int writePosition = {0};
    int delayTime = {500};
    float wet = {0.5};

};
