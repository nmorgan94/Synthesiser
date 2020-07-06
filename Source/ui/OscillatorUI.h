/*
  ==============================================================================

    OscillatorUI.h
    Created: 16 Apr 2020 7:54:49pm
    Author:  Nicholas Morgan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../PluginProcessor.h"

//==============================================================================
/*
*/
class OscillatorUI    : public Component
{
public:
    OscillatorUI(SynthAudioProcessor&, String connectedOscillatorParameter, String connectedMidiOffsetParameter, String connectedGainParameter);
    ~OscillatorUI();

    void paint (Graphics&) override;
    void resized() override;
    void buildOscillatorSlider(Slider&, float, float, float);
    void setComponentNameText(String name);

private:
    SynthAudioProcessor& processor;
    String connectedOscillatorParameter;
    String connectedMidiOffsetParameter;
    String connectedGainParameter;
    ComboBox comboBox;
    Slider midiOffsetSlider, volumeSlider;
    
    std::unique_ptr <AudioProcessorValueTreeState::ComboBoxAttachment> comboBoxAttachment;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> pitchAttachment, volumeAttachment;
    
    
//    AudioProcessorValueTreeState::ComboBoxAttachment comboBoxAttachment;
//    AudioProcessorValueTreeState::SliderAttachment pitchAttachment, volumeAttachment;
   
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorUI)
};
