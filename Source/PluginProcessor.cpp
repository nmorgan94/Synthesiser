/*
 ==============================================================================
 
 This file was auto-generated!
 
 It contains the basic framework code for a JUCE plugin processor.
 
 ==============================================================================
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthAudioProcessor::SynthAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
: AudioProcessor (BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
                  .withInput  ("Input",  AudioChannelSet::stereo(), true)
#endif
                  .withOutput ("Output", AudioChannelSet::stereo(), true)
#endif
                  ), state (*this, nullptr, "state",createParameterLayout())

#endif
{
    synthesiser.clearVoices();
    
    
    for (int i = 0; i < 5; i++)
    {
        synthesiser.addVoice(new SynthVoice());
    }
    
    
    synthesiser.clearSounds();
    synthesiser.addSound(new SynthSound());
}

SynthAudioProcessor::~SynthAudioProcessor()
{
}

//==============================================================================
const String SynthAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SynthAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool SynthAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

bool SynthAudioProcessor::isMidiEffect() const
{
#if JucePlugin_IsMidiEffect
    return true;
#else
    return false;
#endif
}

double SynthAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SynthAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
    // so this should be at least 1, even if you're not really implementing programs.
}

int SynthAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SynthAudioProcessor::setCurrentProgram (int index)
{
}

const String SynthAudioProcessor::getProgramName (int index)
{
    return {};
}

void SynthAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void SynthAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    synthesiser.setCurrentPlaybackSampleRate(sampleRate);
    reverb.setSampleRate(sampleRate);
    oscilloscope.clear();
}

void SynthAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SynthAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
#if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
#else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
        && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;
    
    // This checks if the input layout matches the output layout
#if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
#endif
    
    return true;
#endif
}
#endif

void SynthAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    setSynthesiserVoice();
    
    buffer.clear();
    
    synthesiser.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
    
    setFilterParameters();
    setReverbParameters();
    
    if (getMainBusNumOutputChannels() == 1){
        lowpassIIRFilterLeft.processSamples(buffer.getWritePointer(0), buffer.getNumSamples());
        
        highpassIIRFilterLeft.processSamples(buffer.getWritePointer(0), buffer.getNumSamples());
        
        reverb.processMono (buffer.getWritePointer (0), buffer.getNumSamples());
    }
    else if (getMainBusNumOutputChannels() == 2){
        lowpassIIRFilterLeft.processSamples(buffer.getWritePointer(0), buffer.getNumSamples());
        lowpassIIRFilterRight.processSamples(buffer.getWritePointer(1), buffer.getNumSamples());
        
        highpassIIRFilterLeft.processSamples(buffer.getWritePointer(0), buffer.getNumSamples());
        highpassIIRFilterRight.processSamples(buffer.getWritePointer(1), buffer.getNumSamples());
        
        reverb.processStereo (buffer.getWritePointer (0), buffer.getWritePointer (1), buffer.getNumSamples());
    }
    
    buffer.applyGain(*state.getRawParameterValue("masterGain") * 0.3);
    
    oscilloscope.pushBuffer(buffer);
    oscilloscope.checkIfClipping(buffer.getMagnitude(0, buffer.getNumSamples()));
}

//==============================================================================
bool SynthAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* SynthAudioProcessor::createEditor()
{
    return new SynthAudioProcessorEditor (*this);
}

//==============================================================================
void SynthAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void SynthAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

AudioProcessorValueTreeState::ParameterLayout SynthAudioProcessor::createParameterLayout()
{
    std::vector<std::unique_ptr<RangedAudioParameter>> params;
    
    params.push_back (std::make_unique<AudioParameterFloat>("attack", "Envelope: Attack", 0.1f, 5000.0f, 0.1f));
    params.push_back (std::make_unique<AudioParameterFloat>("decay", "Envelope: Decay", 1.0f, 2000.0f, 1.0f));
    params.push_back (std::make_unique<AudioParameterFloat>("sustain", "Envelope: Sustain", 0.0f, 1.0f, 1.0f));
    params.push_back (std::make_unique<AudioParameterFloat>("release", "Envelope: Release", 0.1f, 5000.0f, 0.1f));
    
    params.push_back (std::make_unique<AudioParameterInt>("osc1", "Osc1", 1, 7, 1));
    params.push_back (std::make_unique<AudioParameterInt>("midiOffset1", "MidiOffset1", -24, 24, 0));
    params.push_back (std::make_unique<AudioParameterFloat>("oscillator1Gain", "Oscillator1Gain", 0.0f, 1.0f,1.0f));
    
    params.push_back (std::make_unique<AudioParameterInt>("osc2", "Osc2", 1, 7, 1));
    params.push_back (std::make_unique<AudioParameterInt>("midiOffset2", "MidiOffset2", -24, 24, 0));
    params.push_back (std::make_unique<AudioParameterFloat>("oscillator2Gain", "Oscillator2Gain", 0.0f, 1.0f,1.0f));
    
    params.push_back (std::make_unique<AudioParameterInt>("osc3", "Osc3", 1, 3, 1));
    params.push_back (std::make_unique<AudioParameterInt>("midiOffset3", "MidiOffset3", -24, 24, 0));
    params.push_back (std::make_unique<AudioParameterFloat>("oscillator3Gain", "Oscillator3Gain", 0.0f, 1.0f,1.0f));
    
    params.push_back (std::make_unique<AudioParameterFloat>("masterGain", "MasterGain", 0.0f, 1.0f, 0.5f));
    
    params.push_back (std::make_unique<AudioParameterFloat>("roomSize", "RoomSize", 0.1f, 1.0f, 0.1f));
    params.push_back (std::make_unique<AudioParameterFloat>("damping", "Damping", 0.1f, 1.0f, 0.1f));
    params.push_back (std::make_unique<AudioParameterFloat>("width", "Width", 0.1f, 1.0f, 0.1f));
    params.push_back (std::make_unique<AudioParameterFloat>("wetLevel", "WetLevel", 0.1f, 1.0f, 0.1f));
    
    params.push_back (std::make_unique<AudioParameterFloat>("lowpassCutoff", "LowpassCutoff", 20.0f, 20000.0f, 20000.0f));
    params.push_back (std::make_unique<AudioParameterFloat>("highpassCutoff", "HighpassCutoff", 20.0f, 20000.0f, 20.0f));
    
    return { params.begin(), params.end() };
}



void SynthAudioProcessor::setSynthesiserVoice(){
    
    for(int i = 0; i < synthesiser.getNumVoices(); i++){
        auto* synthVoice = dynamic_cast<SynthVoice*>(synthesiser.getVoice(i));
        {
            //TODO - value state listener, sampler vid 7
            synthVoice->setEnvelopeParams(*state.getRawParameterValue("attack"),
                                          *state.getRawParameterValue("decay"),
                                          *state.getRawParameterValue("sustain"),
                                          *state.getRawParameterValue("release"));
            
            
            synthVoice->setOscillator(0, *state.getRawParameterValue("osc1"), *state.getRawParameterValue("oscillator1Gain"), *state.getRawParameterValue("midiOffset1"));
            
            synthVoice->setOscillator(1, *state.getRawParameterValue("osc2"), *state.getRawParameterValue("oscillator2Gain"), *state.getRawParameterValue("midiOffset2"));
            
            synthVoice->setOscillator(2, *state.getRawParameterValue("osc3"), *state.getRawParameterValue("oscillator3Gain"), *state.getRawParameterValue("midiOffset3"));
            
            
        }
    }
}

void SynthAudioProcessor::setReverbParameters(){
    reverbParameters.roomSize = *state.getRawParameterValue("roomSize");
    reverbParameters.damping = *state.getRawParameterValue("damping");
    reverbParameters.width = *state.getRawParameterValue("width");
    reverbParameters.wetLevel = *state.getRawParameterValue("wetLevel");
    reverb.setParameters (reverbParameters);
}

void SynthAudioProcessor::setFilterParameters(){
    lowpassIIRCoefficients = IIRCoefficients::makeLowPass(44100, *state.getRawParameterValue("lowpassCutoff"), 3);
    lowpassIIRFilterLeft.setCoefficients(lowpassIIRCoefficients);
    lowpassIIRFilterRight.setCoefficients(lowpassIIRCoefficients);
    
    highpassIIRCoefficients =  IIRCoefficients::makeHighPass(44100, *state.getRawParameterValue("highpassCutoff"), 3);
    highpassIIRFilterLeft.setCoefficients(highpassIIRCoefficients);
    highpassIIRFilterRight.setCoefficients(highpassIIRCoefficients);
}


//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SynthAudioProcessor();
}
