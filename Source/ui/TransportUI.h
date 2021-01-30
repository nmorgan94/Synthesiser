/*
  ==============================================================================

    TransportUI.h
    Created: 30 Jan 2021 7:03:17pm
    Author:  Nicholas Morgan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../PluginProcessor.h"

//==============================================================================
/*
*/
class TransportUI  : public juce::Component,  public Timer
{
public:
    TransportUI(SynthAudioProcessor&);
    ~TransportUI() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    void updateTransportTextDisplay();
    void timerCallback() override;

private:
    SynthAudioProcessor& processor;
    Label label;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TransportUI)
};
