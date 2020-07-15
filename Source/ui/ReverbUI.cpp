/*
  ==============================================================================

    ReverbUI.cpp
    Created: 5 May 2020 8:49:50pm
    Author:  Nicholas Morgan

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ReverbUI.h"

//==============================================================================
ReverbUI::ReverbUI(SynthAudioProcessor& p) : processor(p)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    
    buildReverbSlider(roomSizeSlider, 0.1f, 1.0f, 0.1f, "Room Size");
    buildReverbSlider(dampingSlider, 0.1f, 1.0f, 0.1f, "Damping");
    buildReverbSlider(widthSlider, 0.0f, 1.0f, 0.1f, "Width");
    buildReverbSlider(wetLevelSlider, 0.1f, 1.0f, 0.1f, "Wet Level");
    
    roomSizeAttachment =  std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, "roomSize", roomSizeSlider);
    dampingAttachment =  std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, "damping", dampingSlider);
    widthAttachment =  std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, "width", widthSlider);
    wetLevelAttachment =  std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, "wetLevel", wetLevelSlider);
    
    buildLabel(roomSizeLabel, "Room Size");
    buildLabel(dampingLabel, "Damping");
    buildLabel(widthLabel, "Width");
    buildLabel(wetLevelLabel, "Wet Level");
    
    label.setText("Reverb", dontSendNotification);
    label.setJustificationType (Justification::centred);
    label.setFont (Font (12.00f, Font::plain));
    label.setColour (Label::outlineColourId, Colours::grey);
    
    addAndMakeVisible (label);

}

ReverbUI::~ReverbUI()
{
}

void ReverbUI::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

//    g.setColour (Colours::white);
//    g.setFont (14.0f);
//    g.drawText ("ReverbUI", getLocalBounds(),
//                Justification::centred, true);   // draw some placeholder text
}

void ReverbUI::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    
    auto area = getLocalBounds();
    auto labelArea = area.removeFromBottom(15);
    auto top = area.removeFromTop(area.getHeight()/2);
    
    roomSizeSlider.setBounds(top.removeFromLeft (getWidth() / 2));
    roomSizeLabel.setBounds(68, 105, getWidth(), 10);
    
    dampingSlider.setBounds(top.removeFromLeft (getWidth() / 2));
    dampingLabel.setBounds(256, 105, getWidth(), 10);
    
    widthSlider.setBounds(area.removeFromLeft (getWidth() / 2));
    widthLabel.setBounds(77, 219, getWidth(), 10);
    
    wetLevelSlider.setBounds(area.removeFromLeft (getWidth() / 2));
    wetLevelLabel.setBounds(258, 219, getWidth(), 10);
    
    label.setBounds(labelArea);
    
    
    
}

void ReverbUI::buildReverbSlider(Slider& slider, float minValue, float maxValue, float startingValue, String text){
    
    addAndMakeVisible(slider);
    slider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    slider.setRange(minValue, maxValue);
    slider.setValue (startingValue);
    slider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    slider.setPopupDisplayEnabled (true, false, this);
    slider.setTextValueSuffix(" "+text);

}

void ReverbUI::buildLabel(Label& label, String text){
    label.setText(text, dontSendNotification);
    label.setFont (Font (10.00f, Font::plain));
    addAndMakeVisible (label);
}
