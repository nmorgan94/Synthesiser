/*
 ==============================================================================
 
 SynthVoice.h
 Created: 13 Apr 2020 4:48:12pm
 Author:  Nicholas Morgan
 
 ==============================================================================
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include "./Maximilian/src/maximilian.h"

class OscillatorParams {
    int type;
    float gain;
    int midiNoteOffset;
    
public:
    int getType() {
        return type;
    }
    
    float getGain() {
        return gain;
    }
    
    int getMidiNoteOffset() {
        return midiNoteOffset;
    }

    void setType(int type){
        this->type = type;
    }
    
    void setGain(float gain){
        this->gain = gain;
    }
    
    void setMidiNoteOffset(int midiNoteOffset){
        this->midiNoteOffset = midiNoteOffset;
    }
    
};



class SynthVoice : public SynthesiserVoice
{
    
    
public:
    
    bool canPlaySound (SynthesiserSound* sound) override
    {
        return dynamic_cast <SynthSound*>(sound) != nullptr;
    }
    
    void pitchWheelMoved (int newPitchWheelValue) override
    {
        
    }
    
    void controllerMoved (int controllerNumber, int newControllerValue) override
    {
        
    }
    
    
    
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition) override
    {
        midiKey = midiNoteNumber;
        adsr.noteOn();
    }
    
    void stopNote (float velocity, bool allowTailOff) override
    {
        adsr.noteOff();
        allowTailOff = true;
        
        
        if (velocity == 0)
            clearCurrentNote();
            
    }
    
    void setADSRSampleRate(double sampleRate)
    {
        adsr.setSampleRate(sampleRate);
    }
    
    void setEnvelopeParams(float attack, float decay, float sustain, float release)
    {
        adsrParams.attack = attack;
        adsrParams.decay = decay;
        adsrParams.sustain = sustain;
        adsrParams.release = release;
    }
    
    void setOscillator(int oscillatorNumber, float selection, float gain, int offset){
        
        oscillatorArray[oscillatorNumber].setType(selection);
        oscillatorArray[oscillatorNumber].setGain(gain);
        oscillatorArray[oscillatorNumber].setMidiNoteOffset(offset);
    }
    
    
    double currentSample()
    {
        
        double sampleArray[3];
        
        
        for(int i = 0; i < 3; i++){
            
            switch(oscillatorArray[i].getType())
            {
                case 1:
                    sampleArray[i] = osc[i].square(MidiMessage::getMidiNoteInHertz(midiKey + oscillatorArray[i].getMidiNoteOffset()));
                    break;
                case 2:
                    sampleArray[i] = osc[i].saw(MidiMessage::getMidiNoteInHertz(midiKey + oscillatorArray[i].getMidiNoteOffset()));
                    break;
                case 3:
                    sampleArray[i] = osc[i].triangle(MidiMessage::getMidiNoteInHertz(midiKey + oscillatorArray[i].getMidiNoteOffset()));
                    break;
                case 4:
                    sampleArray[i] = osc[i].sawn(MidiMessage::getMidiNoteInHertz(midiKey + oscillatorArray[i].getMidiNoteOffset()));
                    break;
                case 5:
                    sampleArray[i] = osc[i].impulse(MidiMessage::getMidiNoteInHertz(midiKey + oscillatorArray[i].getMidiNoteOffset()));
                    break;
                case 6:
                    sampleArray[i] = osc[i].noise();
                    break;
                default:
                    sampleArray[i] = osc[i].sinewave(MidiMessage::getMidiNoteInHertz(midiKey + oscillatorArray[i].getMidiNoteOffset()));
                    break;
            }
            

        }
      
        
        return (sampleArray[0] * oscillatorArray[0].getGain() + sampleArray[1] * oscillatorArray[1].getGain() + sampleArray[2] * oscillatorArray[2].getGain());
    }
    
    
    void renderNextBlock (AudioBuffer <float> &outputBuffer, int startSample, int numSamples) override
    {
        adsr.setParameters(adsrParams);
        for (int sample = 0; sample < numSamples; ++sample)
        {
            for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
            {
                outputBuffer.addSample(channel, startSample, adsr.getNextSample() * currentSample());
                
            }
            ++startSample;
        }
        
    }
    
private:
    int midiKey;
    
    ADSR adsr;
    ADSR::Parameters adsrParams;
    
    OscillatorParams oscillatorArray[3];
    maxiOsc osc[3];
    
};


