/*
  ==============================================================================

    CustomSlider.h
    Created: 21 Mar 2021 8:01:49pm
    Author:  Nicholas Morgan

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"



class CustomSlider : public Slider
{
    
    public:
    
    void mouseEnter(const MouseEvent &) override
    {
        setColour (juce::Slider::thumbColourId, Colour(getLookAndFeel().findColour (Slider::thumbColourId).darker()));
    }

    void mouseExit (const MouseEvent &) override
    {
        setColour(juce::Slider::thumbColourId, Colour(getLookAndFeel().findColour (Slider::thumbColourId)));
    }
};

