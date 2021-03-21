/*
  ==============================================================================

    ChorusUI.h
    Created: 6 Feb 2021 11:05:56am
    Author:  Nicholas Morgan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../PluginProcessor.h"

//==============================================================================
/*
*/
class ChorusUI  : public juce::Component
{
public:
    ChorusUI(SynthAudioProcessor&);
    ~ChorusUI() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    void buildChorusSlider(Slider&, String);
    void buildLabel(Label& label, String text);

private:
    SynthAudioProcessor& processor;
    Slider mixSlider, rateSlider, depthSlider, centreDelaySlider, feedbackSlider;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mixAttachment, rateAttachment, depthAttachment, centreDelayAttachment, feedbackAttachment;
    Label label, mixLabel, rateLabel, depthLabel , centreDelayLabel, feedbackLabel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChorusUI)
};
