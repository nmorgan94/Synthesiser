/*
 ==============================================================================
 
 EnvelopeParams.h
 Created: 30 Dec 2020 8:32:06pm
 Author:  Nicholas Morgan
 
 ==============================================================================
 */

#pragma once


class EnvelopeParams
{
public:
    static const float ATTACK_MIN;
    static const float ATTACK_MAX;
    static const float ATTACK_VALUE;
    
    static const float DECAY_MIN;
    static const float DECAY_MAX;
    static const float DECAY_VALUE;
    
    static const float SUSTAIN_MIN;
    static const float SUSTAIN_MAX;
    static const float SUSTAIN_VALUE;
    
    static const float RELEASE_MIN;
    static const float RELEASE_MAX;
    static const float RELEASE_VALUE;
};


class FilterParams
{
public:
    static const float LOWPASS_CUTOFF_MIN;
    static const float LOWPASS_CUTOFF_MAX;
    static const float LOWPASS_CUTOFF_VALUE;
    
    static const float HIGHPASS_CUTOFF_MIN;
    static const float HIGHPASS_CUTOFF_MAX;
    static const float HIGHPASS_CUTOFF_VALUE;
};

class ReverbParams
{
public:
    static const float ROOMSIZE_MIN;
    static const float ROOMSIZE_MAX;
    static const float ROOMSIZE_VALUE;
    
    static const float DAMPING_MIN;
    static const float DAMPING_MAX;
    static const float DAMPING_VALUE;
    
    static const float WIDTH_MIN;
    static const float WIDTH_MAX;
    static const float WIDTH_VALUE;
    
    static const float WETLEVEL_MIN;
    static const float WETLEVEL_MAX;
    static const float WETLEVEL_VALUE;
};

class MasterGainParams
{
public:
    static const float MIN;
    static const float MAX;
    static const float VALUE;
};

class Oscillator1Params
{
public:
    static const int WAVESHAPE_MIN;
    static const int WAVESHAPE_MAX;
    static const int WAVESHAPE_VALUE;
    
    static const int MIDIOFFSET_MIN;
    static const int MIDIOFFSET_MAX;
    static const int MIDIOFFSET_VALUE;
    
    static const float GAIN_MIN;
    static const float GAIN_MAX;
    static const float GAIN_VALUE;
};

class Oscillator2Params
{
public:
    static const int WAVESHAPE_MIN;
    static const int WAVESHAPE_MAX;
    static const int WAVESHAPE_VALUE;
    
    static const int MIDIOFFSET_MIN;
    static const int MIDIOFFSET_MAX;
    static const int MIDIOFFSET_VALUE;
    
    static const float GAIN_MIN;
    static const float GAIN_MAX;
    static const float GAIN_VALUE;
};

class Oscillator3Params
{
public:
    static const int WAVESHAPE_MIN;
    static const int WAVESHAPE_MAX;
    static const int WAVESHAPE_VALUE;
    
    static const int MIDIOFFSET_MIN;
    static const int MIDIOFFSET_MAX;
    static const int MIDIOFFSET_VALUE;
    
    static const float GAIN_MIN;
    static const float GAIN_MAX;
    static const float GAIN_VALUE;
};



class DelayParams
{
public:
    static const float WET_MIN;
    static const float WET_MAX;
    static const float WET_VALUE;
    
    static const int TIME_MIN;
    static const int TIME_MAX;
    static const int TIME_VALUE;
    
    
};
