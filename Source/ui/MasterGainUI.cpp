/*
  ==============================================================================

    MasterGainUI.cpp
    Created: 17 Apr 2020 8:53:31pm
    Author:  Nicholas Morgan

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MasterGainUI.h"

//==============================================================================
MasterGainUI::MasterGainUI(SynthAudioProcessor& p) : processor(p)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    masterGainSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    masterGainSlider.setRange(0, 1);
    masterGainSlider.setValue (0.5);
    masterGainSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    
    masterGainAttachment =  std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.state, "masterGain", masterGainSlider);
}

MasterGainUI::~MasterGainUI()
{

}

void MasterGainUI::paint (Graphics& g)
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
//    g.drawText ("FilterUI", getLocalBounds(),
//                Justification::centred, true);   // draw some placeholder text

}

void MasterGainUI::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    
    addAndMakeVisible(masterGainSlider);
    auto area = getLocalBounds();
    
    masterGainSlider.setBounds(area);

}
