/*
 ==============================================================================
 
 This file was auto-generated!
 
 It contains the basic framework code for a JUCE plugin processor.
 
 ==============================================================================
 */

#pragma once

#include <JuceHeader.h>
#include "SynthVoice.h"
#include "SynthSound.h"
#include "./ui/Oscilloscope.h"
#include "./Constants.h"
#include "./Delay.h"

//==============================================================================
/**
 */
class SynthAudioProcessor  : public AudioProcessor,
                             public ValueTree::Listener
{
public:
    //==============================================================================
    SynthAudioProcessor();
    ~SynthAudioProcessor();
    
    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    
#ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
#endif
    
    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;
    
    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;
    
    //==============================================================================
    const String getName() const override;
    
    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    
    
    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;
    
    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    //==============================================================================
    
    AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    void setParameters();
    void setSynthesiserVoice();
    void setReverbParameters();
    void setFilterParameters();
    void setChorusParameters();
    void setDelayParameters();
    double getLevel();
    
    AudioProcessorValueTreeState state;
    Oscilloscope oscilloscope;
    AudioPlayHead::CurrentPositionInfo lastPosInfo;
    void updateCurrentTimeInfoFromHost (AudioPlayHead::CurrentPositionInfo&);
    
private:
    Synthesiser synthesiser;
    
    Reverb reverb;
    Reverb::Parameters reverbParameters;
    IIRFilter lowpassIIRFilterLeft, lowpassIIRFilterRight, highpassIIRFilterLeft, highpassIIRFilterRight;
    IIRCoefficients lowpassIIRCoefficients, highpassIIRCoefficients;
    double lastSampleRate;
    void valueTreePropertyChanged (ValueTree &treeWhosePropertyHasChanged, const Identifier &property) override;
    std::atomic<bool> shouldUpdate { true };
    
    enum
    {
        chorus
    };
    dsp::ProcessorChain<dsp::Chorus<float>> processorChain;
    
    Delay delay;
    
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthAudioProcessor)
};
