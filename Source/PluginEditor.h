/*
 ==============================================================================
 
 This file was auto-generated!
 
 It contains the basic framework code for a JUCE plugin editor.
 
 ==============================================================================
 */

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "./ui/EnvelopeUI.h"
#include "./ui/OscillatorUI.h"
#include "./ui/ReverbUI.h"
#include "./ui/MasterGainUI.h"


//==============================================================================
/**
 */
class SynthAudioProcessorEditor  : public AudioProcessorEditor,  public Timer
{
public:
    SynthAudioProcessorEditor (SynthAudioProcessor&);
    ~SynthAudioProcessorEditor();
    
    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void timerCallback() override;

   
    
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SynthAudioProcessor& processor;
    
    EnvelopeUI envelopeUI;
    OscillatorUI oscillatorUI;
    OscillatorUI oscillator2UI;
    OscillatorUI oscillator3UI;
    ReverbUI reverbUI;
    MasterGainUI masterGainUI;
    
   
    

    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthAudioProcessorEditor)
};
