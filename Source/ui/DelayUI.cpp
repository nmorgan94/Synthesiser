/*
  ==============================================================================

    DelayUI.cpp
    Created: 6 Feb 2021 11:05:41am
    Author:  Nicholas Morgan

  ==============================================================================
*/

#include <JuceHeader.h>
#include "DelayUI.h"

//==============================================================================
DelayUI::DelayUI(SynthAudioProcessor& p) : processor(p)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    buildDelaySlider(wetSlider, "Wet");
    buildDelaySlider(timeSlider, "Time");
    
    wetAttachment =  std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, "delayWet", wetSlider);
    timeAttachment =  std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, "delayTime", timeSlider);
    
    buildLabel(wetLabel, "Wet");
    buildLabel(timeLabel, "Time");
    
    label.setText("Delay", dontSendNotification);
    label.setJustificationType (Justification::centred);
    label.setFont (Font (12.00f, Font::plain));
    label.setColour (Label::outlineColourId, Colours::grey);
    
    addAndMakeVisible(label);

}

DelayUI::~DelayUI()
{
}

void DelayUI::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

}

void DelayUI::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    
    auto area = getLocalBounds();
    auto labelArea = area.removeFromBottom(15);
    
     const int height = 57;
    
    wetSlider.setBounds(area.removeFromLeft (getWidth() / 2));
    timeSlider.setBounds(area.removeFromLeft (getWidth() / 2));
    
    wetLabel.setBounds(50, height, getWidth(), 10);
    timeLabel.setBounds(171, height, getWidth(), 10);
    
    label.setBounds(labelArea);

}

void DelayUI::buildDelaySlider(Slider& slider, String text){
    
    addAndMakeVisible(slider);
    slider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    slider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    slider.setPopupDisplayEnabled (true, false, this);
    slider.setNumDecimalPlacesToDisplay(2);
    slider.setTextValueSuffix(" "+text);
}

void DelayUI::buildLabel(Label& label, String text){
    label.setText(text, dontSendNotification);
    label.setFont (Font (10.00f, Font::plain));
    addAndMakeVisible (label);
    
}
