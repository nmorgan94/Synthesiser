/*
  ==============================================================================

    Constants.cpp
    Created: 3 Jan 2021 1:34:13pm
    Author:  Nicholas Morgan

  ==============================================================================
*/

#include "Constants.h"

const float EnvelopeParams::ATTACK_MIN = 0.1f;
const float EnvelopeParams::ATTACK_MAX = 5.0f;
const float EnvelopeParams::ATTACK_VALUE = 0.1f;

const float EnvelopeParams::DECAY_MIN = 0.1f;
const float EnvelopeParams::DECAY_MAX = 2.0f;
const float EnvelopeParams::DECAY_VALUE = 0.1f;

const float EnvelopeParams::SUSTAIN_MIN = 0.0f;
const float EnvelopeParams::SUSTAIN_MAX = 1.0f;
const float EnvelopeParams::SUSTAIN_VALUE = 1.0f;

const float EnvelopeParams::RELEASE_MIN = 0.1f;
const float EnvelopeParams::RELEASE_MAX = 5.0f;
const float EnvelopeParams::RELEASE_VALUE = 0.1f;

// ==============================================================================

const float FilterParams::LOWPASS_CUTOFF_MIN = 20.0f;
const float FilterParams::LOWPASS_CUTOFF_MAX = 20000.0f;
const float FilterParams::LOWPASS_CUTOFF_VALUE = 20000.0f;

const float FilterParams::HIGHPASS_CUTOFF_MIN = 20.0f;
const float FilterParams::HIGHPASS_CUTOFF_MAX = 20000.0f;
const float FilterParams::HIGHPASS_CUTOFF_VALUE = 20.0f;

// ==============================================================================

const float ReverbParams::ROOMSIZE_MIN = 0.1f;
const float ReverbParams::ROOMSIZE_MAX = 1.0f;
const float ReverbParams::ROOMSIZE_VALUE = 0.1f;

const float ReverbParams::DAMPING_MIN = 0.1f;
const float ReverbParams::DAMPING_MAX = 1.0f;
const float ReverbParams::DAMPING_VALUE = 0.1f;
 
const float ReverbParams::WIDTH_MIN = 0.1f;
const float ReverbParams::WIDTH_MAX = 1.0f;
const float ReverbParams::WIDTH_VALUE = 0.1f;
 
const float ReverbParams::WETLEVEL_MIN = 0.0f;
const float ReverbParams::WETLEVEL_MAX = 1.0f;
const float ReverbParams::WETLEVEL_VALUE = 0.0f;

// ==============================================================================

const float MasterGainParams::MIN = 0.0f;
const float MasterGainParams::MAX = 1.0f;
const float MasterGainParams::VALUE = 0.5f;

// ==============================================================================

const int Oscillator1Params::WAVESHAPE_MIN = 1;
const int Oscillator1Params::WAVESHAPE_MAX = 7;
const int Oscillator1Params::WAVESHAPE_VALUE = 1;

const int Oscillator1Params::MIDIOFFSET_MIN = -24;
const int Oscillator1Params::MIDIOFFSET_MAX = 24;
const int Oscillator1Params::MIDIOFFSET_VALUE = 0;

const float Oscillator1Params::GAIN_MIN = 0.0f;
const float Oscillator1Params::GAIN_MAX = 1.0f;
const float Oscillator1Params::GAIN_VALUE = 1.0f;

// ==============================================================================

const int Oscillator2Params::WAVESHAPE_MIN = 1;
const int Oscillator2Params::WAVESHAPE_MAX = 7;
const int Oscillator2Params::WAVESHAPE_VALUE = 1;

const int Oscillator2Params::MIDIOFFSET_MIN = -24;
const int Oscillator2Params::MIDIOFFSET_MAX = 24;
const int Oscillator2Params::MIDIOFFSET_VALUE = 0;

const float Oscillator2Params::GAIN_MIN = 0.0f;
const float Oscillator2Params::GAIN_MAX = 1.0f;
const float Oscillator2Params::GAIN_VALUE = 0.0f;

// ==============================================================================

const int Oscillator3Params::WAVESHAPE_MIN = 1;
const int Oscillator3Params::WAVESHAPE_MAX = 7;
const int Oscillator3Params::WAVESHAPE_VALUE = 1;

const int Oscillator3Params::MIDIOFFSET_MIN = -24;
const int Oscillator3Params::MIDIOFFSET_MAX = 24;
const int Oscillator3Params::MIDIOFFSET_VALUE = 0;

const float Oscillator3Params::GAIN_MIN = 0.0f;
const float Oscillator3Params::GAIN_MAX = 1.0f;
const float Oscillator3Params::GAIN_VALUE = 0.0f;

// ==============================================================================
