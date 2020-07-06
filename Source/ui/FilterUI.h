/*
  ==============================================================================

    FilterUI.h
    Created: 19 Apr 2020 12:02:57am
    Author:  Nicholas Morgan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class FilterUI    : public Component
{
public:
    FilterUI();
    ~FilterUI();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterUI)
};
