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
//attackAttachment       (processor.state, "attack",  attackSlider),
//decayAttachment      (processor.state, "decay", decaySlider),
//sustainAttachment       (processor.state, "sustain",  sustainSlider),
//releaseAttachment      (processor.state, "release", releaseSlider)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
   
    
    buildEnvelopeSlider(attackSlider, 0.1f, 5000.0f, 0.1f);
    buildEnvelopeSlider(decaySlider, 1.0f, 2000.0f, 1.0f);
    buildEnvelopeSlider(sustainSlider, 0.0f, 1.0f, 1.0f);
    buildEnvelopeSlider(releaseSlider, 0.1f, 5000.0f, 0.1f);
    
    attackAttachment =  std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, "attack", attackSlider);
    decayAttachment =  std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, "decay", decaySlider);
    sustainAttachment =  std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, "sustain", sustainSlider);
    releaseAttachment =  std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, "release", releaseSlider);
    
    label.setText("Envelope", dontSendNotification);
    label.setJustificationType (Justification::centred);
    
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
    
    attackSlider.setBounds(area.removeFromLeft (getWidth() / 4));
    decaySlider.setBounds(area.removeFromLeft (getWidth() / 4));
    sustainSlider.setBounds(area.removeFromLeft (getWidth() / 4));
    releaseSlider.setBounds(area.removeFromLeft (getWidth() / 4));
    
   // setSliderStateFromParameterValue();
}

void EnvelopeUI::buildEnvelopeSlider(Slider& slider, float minValue, float maxValue, float startingValue){
    
    addAndMakeVisible(slider);
    slider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    slider.setRange(minValue, maxValue);
    slider.setValue (startingValue);
    slider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
}

//void EnvelopeUI::setSliderStateFromParameterValue(){
//    attackSlider.setValue(*processor.state.getRawParameterValue("attack"));
//    decaySlider.setValue(*processor.state.getRawParameterValue("decay"));
//    sustainSlider.setValue(*processor.state.getRawParameterValue("sustain"));
//    releaseSlider.setValue(*processor.state.getRawParameterValue("release"));
//}
