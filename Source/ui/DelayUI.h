/*
  ==============================================================================

    DelayUI.h
    Created: 6 Feb 2021 11:05:41am
    Author:  Nicholas Morgan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../PluginProcessor.h"

//==============================================================================
/*
*/
class DelayUI  : public Component
{
public:
    DelayUI(SynthAudioProcessor&);
    ~DelayUI() override;

    void paint (Graphics&) override;
    void resized() override;
    void buildDelaySlider(Slider&, String);
    void buildLabel(Label& label, String text);

private:
    SynthAudioProcessor& processor;
    Slider wetSlider, timeSlider;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> wetAttachment, timeAttachment;
    Label label, wetLabel, timeLabel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DelayUI)
};
