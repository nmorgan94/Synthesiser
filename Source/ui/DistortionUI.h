/*
  ==============================================================================

    DistortionUI.h
    Created: 6 Feb 2021 5:50:24pm
    Author:  Nicholas Morgan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class DistortionUI  : public juce::Component
{
public:
    DistortionUI();
    ~DistortionUI() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DistortionUI)
};
