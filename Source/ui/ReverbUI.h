/*
  ==============================================================================

    ReverbUI.h
    Created: 5 May 2020 8:49:50pm
    Author:  Nicholas Morgan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../PluginProcessor.h"

//==============================================================================
/*
*/
class ReverbUI    : public Component
{
public:
    ReverbUI(SynthAudioProcessor&);
    ~ReverbUI();

    void paint (Graphics&) override;
    void resized() override;
    void buildReverbSlider(Slider&, float, float, float);

private:
  
    
    SynthAudioProcessor& processor;
    
    Slider roomSizeSlider, dampingSlider, widthSlider, wetLevelSlider;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> roomSizeAttachment, dampingAttachment, widthAttachment, wetLevelAttachment;
    
    Label label;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ReverbUI)
};
