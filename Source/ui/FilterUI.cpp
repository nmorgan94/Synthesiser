/*
  ==============================================================================

    FilterUI.cpp
    Created: 19 Apr 2020 12:02:57am
    Author:  Nicholas Morgan

  ==============================================================================
*/

#include <JuceHeader.h>
#include "FilterUI.h"

//==============================================================================
FilterUI::FilterUI(SynthAudioProcessor& p) : processor(p)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    buildFilterSlider(lowpassSlider, 20.0f, 20000.0f, 20000.0f, "lCutoff");
    buildFilterSlider(highpassSlider, 20.0f, 20000.0f, 20.0f, "hCutoff");
    
    lowpassAttachment =  std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, "lowpassCutoff", lowpassSlider);
    highpassAttachment =  std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, "highpassCutoff", highpassSlider);
    
    label.setText("Filter", dontSendNotification);
    label.setJustificationType (Justification::centred);
    label.setFont (Font (12.00f, Font::plain));
    label.setColour (Label::outlineColourId, Colours::grey);
    
    addAndMakeVisible(label);
}

FilterUI::~FilterUI()
{
}

void FilterUI::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    
}

void FilterUI::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    
    auto area = getLocalBounds();
    auto labelArea = area.removeFromBottom(15);
    
    highpassSlider.setBounds(area.removeFromLeft (getWidth() / 2));
    lowpassSlider.setBounds(area.removeFromLeft (getWidth() / 2));

    
    label.setBounds(labelArea);

}

void FilterUI::buildFilterSlider(Slider& slider, float minValue, float maxValue, float startingValue, String text){
    
    addAndMakeVisible(slider);
    slider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    slider.setRange(minValue, maxValue);
    slider.setValue (startingValue);
    slider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    slider.setPopupDisplayEnabled (true, false, this);
    slider.setNumDecimalPlacesToDisplay(2);
    slider.setTextValueSuffix(" "+text);
}
