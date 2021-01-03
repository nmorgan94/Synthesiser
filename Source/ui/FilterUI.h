/*
  ==============================================================================

    FilterUI.h
    Created: 19 Apr 2020 12:02:57am
    Author:  Nicholas Morgan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../PluginProcessor.h"

//==============================================================================
/*
*/
class FilterUI    : public Component
{
public:
    FilterUI(SynthAudioProcessor&);
    ~FilterUI();

    void paint (Graphics&) override;
    void resized() override;
    void buildFilterSlider(Slider&, String);
    void buildLabel(Label& label, String text);

private:
    SynthAudioProcessor& processor;
    Slider lowpassSlider, highpassSlider;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> lowpassAttachment, highpassAttachment;
    Label label, lowpassLabel, highpassLabel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterUI)
};
