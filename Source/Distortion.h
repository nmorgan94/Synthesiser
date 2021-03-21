/*
  ==============================================================================

    Distortion.h
    Created: 6 Feb 2021 5:50:07pm
    Author:  Nicholas Morgan

  ==============================================================================
*/

#pragma once

class Distortion {

public:
    
    Distortion(float thresh):
    amount(thresh)
    
    {
        
    }

    float distort(float sample, float thresh)

    {
        
        float output;
        float input = sample;
        float k = 2*thresh/ (1-thresh);
        
        output = ((1+k)*input/ (1+k*std::abs(input)));
        
        return output;
        
    }
    
    void set_distortion_amount(float thresh)
    {
        m_amount = thresh;
    }
    
    float get_distortion_amount(float thresh)
    {
        return amount;
    }
    
private:
    
    float amount;
    
    
};
