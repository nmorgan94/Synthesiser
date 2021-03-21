/*
 ==============================================================================
 
 Oscilloscope.h
 Created: 25 Apr 2020 10:03:18pm
 Author:  Nicholas Morgan
 
 ==============================================================================
 */

#pragma once

#include <JuceHeader.h>


class Oscilloscope : public AudioVisualiserComponent
{
public:
    Oscilloscope() : AudioVisualiserComponent(1){
        setBufferSize(128);
        setSamplesPerBlock(16);
        
    }
    
    void checkIfClipping(double signal){
        
        isClipping = signal > 1 ? true : false;
        
    }
    
    void paintChannel (Graphics& g, Rectangle<float> area, const Range<float>* levels, int numLevels, int nextSample) override
    {
        Path p;
        getChannelAsPath (p, levels, numLevels, nextSample);
        
        isClipping ? g.setColour(Colours::red) : g.setColour(Colour(getLookAndFeel().findColour (Slider::thumbColourId)));
        
        g.fillPath (p, AffineTransform::fromTargetPoints (0.0f, -1.0f,               area.getX(), area.getY(),
                                                          0.0f, 1.0f,                area.getX(), area.getBottom(),
                                                          (float) numLevels, -1.0f,  area.getRight(), area.getY()));
        }
        
        
    private:
        bool isClipping;
        
        };
