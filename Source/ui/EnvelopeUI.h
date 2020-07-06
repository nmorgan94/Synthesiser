/*
  ==============================================================================

    EnvelopeUI.h
    Created: 15 Apr 2020 8:17:28pm
    Author:  Nicholas Morgan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../PluginProcessor.h"

//==============================================================================
/*
*/
class EnvelopeUI    : public Component
{
public:
    EnvelopeUI(SynthAudioProcessor&);
    ~EnvelopeUI();

    void paint (Graphics&) override;
    void resized() override;
    void buildEnvelopeSlider(Slider&, float, float, float);
    void setSliderStateFromParameterValue();

private:
    SynthAudioProcessor& processor;
    
    Slider attackSlider, decaySlider, sustainSlider, releaseSlider;
   // AudioProcessorValueTreeState::SliderAttachment attackAttachment, decayAttachment, sustainAttachment, releaseAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> attackAttachment, decayAttachment, sustainAttachment, releaseAttachment;
    
    Label label;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EnvelopeUI)
};
