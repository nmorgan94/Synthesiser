/*
  ==============================================================================

    TransportUI.cpp
    Created: 30 Jan 2021 7:03:17pm
    Author:  Nicholas Morgan

  ==============================================================================
*/

#include <JuceHeader.h>
#include "TransportUI.h"

//==============================================================================
TransportUI::TransportUI(SynthAudioProcessor& p) : processor(p)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    label.setJustificationType (Justification::centred);
    addAndMakeVisible (label);
    startTimerHz (30);
}

TransportUI::~TransportUI()
{
}

void TransportUI::paint (juce::Graphics& g)
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

void TransportUI::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    
    auto area = getLocalBounds();
    label.setBounds(area);
    


}

void TransportUI::timerCallback () 
{

    updateTransportTextDisplay();
}


void TransportUI::updateTransportTextDisplay()
{
    MemoryOutputStream displayText;

    displayText << String (processor.lastPosInfo.bpm) << " bpm\n"
    << processor.lastPosInfo.timeSigNumerator << '/' << processor.lastPosInfo.timeSigDenominator << "\n";

    label.setText (displayText.toString(), dontSendNotification);
}
