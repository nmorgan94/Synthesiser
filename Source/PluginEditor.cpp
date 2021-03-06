/*
 ==============================================================================
 
 This file was auto-generated!
 
 It contains the basic framework code for a JUCE plugin editor.
 
 ==============================================================================
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthAudioProcessorEditor::SynthAudioProcessorEditor(SynthAudioProcessor &p)
    : AudioProcessorEditor(&p), processor(p), envelopeUI(p), oscillatorUI(p, "osc1", "midiOffset1", "oscillator1Gain"), oscillator2UI(p, "osc2", "midiOffset2", "oscillator2Gain"), oscillator3UI(p, "osc3", "midiOffset3", "oscillator3Gain"), reverbUI(p), filterUI(p), masterGainUI(p), transportUI(p), delayUI(p), chorusUI(p)

{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(1000, 650);

    addAndMakeVisible(&envelopeUI);
    addAndMakeVisible(&oscillatorUI);
    addAndMakeVisible(&oscillator2UI);
    addAndMakeVisible(&oscillator3UI);
    addAndMakeVisible(&masterGainUI);
    addAndMakeVisible(&reverbUI);
    addAndMakeVisible(&filterUI);
    addAndMakeVisible(&transportUI);
    addAndMakeVisible(&processor.oscilloscope);
    addAndMakeVisible(&delayUI);
    addAndMakeVisible(&chorusUI);
}

SynthAudioProcessorEditor::~SynthAudioProcessorEditor()
{
}

//==============================================================================
void SynthAudioProcessorEditor::paint(Graphics &g)
{

    String comileTime = Time::getCompilationDate().toString(true, true);

    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));

    g.setColour(Colours::white);
    g.setFont(15.0f);
    //g.drawFittedText (comileTime, getLocalBounds(), Justification::centred, 1);
}

void SynthAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    auto area = getLocalBounds();
    auto leftSide = area.removeFromLeft(getWidth() / 2);
    auto footer = area.removeFromBottom(getHeight() / 4);

    oscillatorUI.setBounds(leftSide.removeFromTop(getHeight() / 4));
    oscillator2UI.setBounds(leftSide.removeFromTop(getHeight() / 4));
    oscillator3UI.setBounds(leftSide.removeFromTop(getHeight() / 4));
    processor.oscilloscope.setBounds(leftSide.removeFromTop(getHeight() / 4));
    
    auto reverbAndChorusArea = area.removeFromBottom(getHeight() / 2);
    reverbUI.setBounds(reverbAndChorusArea.removeFromLeft(getWidth() / 4));
    chorusUI.setBounds(reverbAndChorusArea.removeFromRight(getWidth() / 4));
    
    auto delayAndFilterArea = area.removeFromLeft(area.getWidth() / 2);
    
    delayUI.setBounds(delayAndFilterArea.removeFromTop(delayAndFilterArea.getHeight() / 2));
    filterUI.setBounds(delayAndFilterArea);
    transportUI.setBounds(area.removeFromTop(getHeight() / 12));
    masterGainUI.setBounds(area);
    
    envelopeUI.setBounds(footer);
}
