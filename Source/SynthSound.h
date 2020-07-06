/*
  ==============================================================================

    SynthSound.h
    Created: 13 Apr 2020 4:48:00pm
    Author:  Nicholas Morgan

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"



class SynthSound : public SynthesiserSound
{
    
public:
    bool appliesToNote (int midiNoteNumber) override
    {
        return true;
    }
    
    bool appliesToChannel (int midiNoteNumber) override
    {
        return true;
    }
};