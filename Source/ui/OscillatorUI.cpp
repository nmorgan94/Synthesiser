/*
 ==============================================================================
 
 OscillatorUI.cpp
 Created: 16 Apr 2020 7:54:49pm
 Author:  Nicholas Morgan
 
 ==============================================================================
 */

#include <JuceHeader.h>
#include "OscillatorUI.h"

//==============================================================================
OscillatorUI::OscillatorUI(SynthAudioProcessor& p, String oscillatorParameter, String midiOffsetParameter, String gainParameter) : processor(p),

connectedOscillatorParameter(oscillatorParameter),
connectedMidiOffsetParameter(midiOffsetParameter),
connectedGainParameter(gainParameter)
//comboBoxAttachment  (processor.state, connectedOscillatorParameter, comboBox),
//pitchAttachment     (processor.state, connectedMidiOffsetParameter,  midiOffsetSlider),
//volumeAttachment    (processor.state, connectedGainParameter,  volumeSlider)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    addAndMakeVisible(&comboBox);
    comboBox.addItemList({"Square", "Saw", "Triangle", "Sawn", "Impulse", "Noise", "Sine"}, 1);
    
    comboBox.setJustificationType(Justification::centred);
    
    buildOscillatorSlider(midiOffsetSlider, -24, 24, 0);
    midiOffsetSlider.setRange(-24, 24, 0);
    buildOscillatorSlider(volumeSlider, 0.0, 1.0, 1.0);
    DBG(connectedOscillatorParameter);
    comboBoxAttachment = std::make_unique<AudioProcessorValueTreeState::ComboBoxAttachment> (processor.state, connectedOscillatorParameter, comboBox);

    pitchAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, connectedMidiOffsetParameter, midiOffsetSlider);
    
    volumeAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, connectedGainParameter, volumeSlider);
    
    
    
}

OscillatorUI::~OscillatorUI()
{
     // DBG(*processor.state.getRawParameterValue(connectedParameter));
}

void OscillatorUI::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
     draws some placeholder text to get you started.
     
     You should replace everything in this method with your own
     drawing code..
     */
    
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background
    
    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component
    
    g.setColour (Colours::white);
    g.setFont (14.0f);

}

void OscillatorUI::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    
    auto area = getLocalBounds();
    comboBox.setBounds(area.removeFromLeft(getWidth() /2).reduced(20));
    //comboBox.setSelectedId(*processor.state.getRawParameterValue(connectedOscillatorParameter));
    midiOffsetSlider.setBounds(area.removeFromLeft(getWidth() /4));
    volumeSlider.setBounds(area.removeFromLeft(getWidth() /4));
    
}

void OscillatorUI::buildOscillatorSlider(Slider& slider, float minValue, float maxValue, float startingValue){
    
    addAndMakeVisible(slider);
    slider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    slider.setRange(minValue, maxValue);
    slider.setValue (startingValue);
    slider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
}
