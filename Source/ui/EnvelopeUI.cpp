/*
  ==============================================================================

    EnvelopeUI.cpp
    Created: 15 Apr 2020 8:17:28pm
    Author:  Nicholas Morgan

  ==============================================================================
*/

#include <JuceHeader.h>
#include "EnvelopeUI.h"

//==============================================================================
EnvelopeUI::EnvelopeUI(SynthAudioProcessor& p) : processor(p)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
   
    
    buildEnvelopeSlider(attackSlider, 0.1f, 5000.0f, 0.1f, "Attack");
    buildEnvelopeSlider(decaySlider, 1.0f, 2000.0f, 1.0f, "Decay");
    buildEnvelopeSlider(sustainSlider, 0.0f, 1.0f, 1.0f, "Susttain");
    buildEnvelopeSlider(releaseSlider, 0.1f, 5000.0f, 0.1f, "Release");
    
    attackAttachment =  std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, "attack", attackSlider);
    decayAttachment =  std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, "decay", decaySlider);
    sustainAttachment =  std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, "sustain", sustainSlider);
    releaseAttachment =  std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, "release", releaseSlider);
    
    buildLabel(attackLabel, "Attack");
    buildLabel(decayLabel, "Decay");
    buildLabel(sustainLabel, "Sustain");
    buildLabel(releaseLabel, "Release");
    
    label.setText("Envelope", dontSendNotification);
    label.setJustificationType (Justification::centred);
    label.setFont (Font (12.00f, Font::plain));
    label.setColour (Label::outlineColourId, Colours::grey);
    
    addAndMakeVisible (label);
    
}

EnvelopeUI::~EnvelopeUI()
{
}

void EnvelopeUI::paint (Graphics& g)
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

void EnvelopeUI::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    
    auto area = getLocalBounds();
    auto labelArea = area.removeFromBottom(15);
    
    attackSlider.setBounds(area.removeFromLeft (getWidth() / 4));
    attackLabel.setBounds(30, 90, getWidth(), 10);
    
    decaySlider.setBounds(area.removeFromLeft (getWidth() / 4));
    decayLabel.setBounds(123, 90, getWidth(), 10);
    
    sustainSlider.setBounds(area.removeFromLeft (getWidth() / 4));
    sustainLabel.setBounds(213, 90, getWidth(), 10);
    
    releaseSlider.setBounds(area.removeFromLeft (getWidth() / 4));
    releaseLabel.setBounds(305, 90, getWidth(), 10);
    
    label.setBounds(labelArea);
}

void EnvelopeUI::buildEnvelopeSlider(Slider& slider, float minValue, float maxValue, float startingValue, String text){
    
    addAndMakeVisible(slider);
    slider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    slider.setRange(minValue, maxValue);
    slider.setValue (startingValue);
    slider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
   // slider.setPopupDisplayEnabled (true, false, this);
   // slider.setTextValueSuffix(" "+text);
}

void EnvelopeUI::buildLabel(Label& label, String text){
    label.setText(text, dontSendNotification);
    label.setFont (Font (10.00f, Font::plain));
    addAndMakeVisible (label);
    
}
