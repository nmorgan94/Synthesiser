/*
  ==============================================================================

    ChorusUI.cpp
    Created: 6 Feb 2021 11:05:56am
    Author:  Nicholas Morgan

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ChorusUI.h"

//==============================================================================
ChorusUI::ChorusUI(SynthAudioProcessor& p) : processor(p)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    buildChorusSlider(mixSlider, "Mix");
    buildChorusSlider(rateSlider, "Rate");
    buildChorusSlider(depthSlider, "Depth");
    buildChorusSlider(centreDelaySlider, "Centre Delay");
    buildChorusSlider(feedbackSlider, "Feedback");
    
    mixAttachment =  std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, "chorusMix", mixSlider);
    rateAttachment =  std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, "chorusRate", rateSlider);
    depthAttachment =  std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, "chorusDepth", depthSlider);
    centreDelayAttachment =  std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, "chorusCentreDelay", centreDelaySlider);
    feedbackAttachment =  std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, "chorusFeedback", feedbackSlider);
    
    buildLabel(mixLabel, "Mix");
    buildLabel(rateLabel, "Rate");
    buildLabel(depthLabel, "Depth");
    buildLabel(centreDelayLabel, "Centre Delay");
    buildLabel(feedbackLabel, "Feedback");
    
    label.setText("Chorus", dontSendNotification);
    label.setJustificationType (Justification::centred);
    label.setFont (Font (12.00f, Font::plain));
    label.setColour (Label::outlineColourId, Colours::grey);

    addAndMakeVisible(label);

}

ChorusUI::~ChorusUI()
{
}

void ChorusUI::paint (juce::Graphics& g)
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

void ChorusUI::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    
    auto area = getLocalBounds();
    auto labelArea = area.removeFromBottom(15);
    auto top = area.removeFromTop(area.getHeight()/2);
    
    feedbackSlider.setBounds(top.removeFromLeft(getWidth() / 2).reduced(20));
//    roomSizeLabel.setBounds(68, 105, getWidth(), 10);
    
    rateSlider.setBounds(top.removeFromLeft (getWidth() / 2).reduced(20));
//    dampingLabel.setBounds(256, 105, getWidth(), 10);
    
    depthSlider.setBounds(area.removeFromLeft (getWidth() / 2).reduced(20));
//    widthLabel.setBounds(77, 219, getWidth(), 10);
    
    centreDelaySlider.setBounds(area.removeFromLeft (getWidth() / 2).reduced(20));
//    wetLevelLabel.setBounds(258, 219, getWidth(), 10);
    
    mixSlider.setBounds(getLocalBounds().reduced(75));
    
    label.setBounds(labelArea);

}

void ChorusUI::buildChorusSlider(Slider& slider, String text){
    
    addAndMakeVisible(slider);
    slider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    slider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    slider.setPopupDisplayEnabled (true, false, this);
    slider.setNumDecimalPlacesToDisplay(2);
    slider.setTextValueSuffix(" "+text);
}

void ChorusUI::buildLabel(Label& label, String text){
    label.setText(text, dontSendNotification);
    label.setFont (Font (10.00f, Font::plain));
    addAndMakeVisible (label);
    
}
