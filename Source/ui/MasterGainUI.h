/*
  ==============================================================================

    MasterGainUI.h
    Created: 17 Apr 2020 8:53:31pm
    Author:  Nicholas Morgan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../PluginProcessor.h"

//==============================================================================
/*
*/
class MasterGainUI    : public Component
{
public:
    MasterGainUI(SynthAudioProcessor&);
    ~MasterGainUI();

    void paint (Graphics&) override;
    void resized() override;

private:
    SynthAudioProcessor& processor;
    Slider masterGainSlider;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> masterGainAttachment;
    Label label;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MasterGainUI)
};
