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
    
    
    buildReverbSlider(roomSizeSlider, 0.1f, 1.0f, 0.1f);
    buildReverbSlider(dampingSlider, 0.1f, 1.0f, 0.1f);
    buildReverbSlider(widthSlider, 0.0f, 1.0f, 0.1f);
    buildReverbSlider(wetLevelSlider, 0.1f, 1.0f, 0.1f);
    
    roomSizeAttachment =  std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, "roomSize", roomSizeSlider);
    dampingAttachment =  std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, "damping", dampingSlider);
    widthAttachment =  std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, "width", widthSlider);
    wetLevelAttachment =  std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, "wetLevel", wetLevelSlider);
    

    label.setText("Reverb", dontSendNotification);
    label.setJustificationType (Justification::centred);

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
    auto labelArea = area.removeFromBottom(25);
    auto top = area.removeFromTop(area.getHeight()/2);
    
    roomSizeSlider.setBounds(top.removeFromLeft (getWidth() / 2));
    dampingSlider.setBounds(top.removeFromLeft (getWidth() / 2));
    widthSlider.setBounds(area.removeFromLeft (getWidth() / 2));
    wetLevelSlider.setBounds(area.removeFromLeft (getWidth() / 2));
    
    label.setBounds(labelArea);
    
}

void ReverbUI::buildReverbSlider(Slider& slider, float minValue, float maxValue, float startingValue){
    
    addAndMakeVisible(slider);
    slider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    slider.setRange(minValue, maxValue);
    slider.setValue (startingValue);
    slider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
}
