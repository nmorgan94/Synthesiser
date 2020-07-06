/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== README.md ==================
static const unsigned char temp_binary_data_0[] =
"```                                     \n"
"  _____ _____ ___   __ _  _____  __ __   __ ____  ____  \n"
" /     \\\\_   \\\\  \\/  /  |/     \\|  |  | |  \\_   \\/    \\\n"
"|  Y Y  \\/ /_ \\>    <|  |  Y Y  \\  |  |_|  |/ /_ \\  Y  \\\n"
"|__|_|  (___  /__/\\__\\__|__|_|  /__|____/__(___  /__|  /\n"
"      \\/    \\/                \\/               \\/    \\/\n"
"```\n"
"![version](https://img.shields.io/badge/version-2.2-red)\n"
"[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/mimic-sussex/eppEditor/blob/master/LICENSE)\n"
"\n"
"<br />\n"
"\n"
"### What's Maximilian?\n"
"\n"
"Maximilian is a cross-platform and multi-target audio synthesis and signal processing library. It was written in C++ and provides bindings to Javascript. It's compatible with native implementations for MacOS, Windows, Linux and iOS systems, as well a"
"s client-side browser-based applications. The main features are:\n"
"\n"
"- sample playback, recording and looping\n"
"- support for WAV and OGG files.\n"
"- a selection of oscillators and filters\n"
"- enveloping\n"
"- multichannel mixing for 1, 2, 4 and 8 channel setups\n"
"- controller mapping functions\n"
"- effects including delay, distortion, chorus, flanging\n"
"- granular synthesis, including time and pitch stretching\n"
"- atom synthesis\n"
"- real-time music information retrieval functions: spectrum analysis, spectral features, octave analysis, Bark scale analysis, and MFCCs\n"
"- example projects for Windows and MacOS, susing command line and OpenFrameworks environments\n"
"- example projects for Firefox and Chromium-based browsers using the Web Audio API ScriptProcessorNode (deprecated!)\n"
"- example projects for Chromium-based browsers using the Web Audio API AudioWorklet (e.g. Chrome, Brave, Edge, Opera, Vivaldi)\n"
"\n"
"\n"
"### Basic Examples\n"
"\n"
"You can choose between using RTAudio and PortAudio drivers in player.h by uncommenting the appropriate line.  To use PortAudio, you will need to compile the portAudio library from http://http://www.portaudio.com/ and link it with your executable.\n"
"\n"
"Examples demonstrating different features can be found in the maximilian_examples folder.  To try them, replace the contents of main.cpp with the contents of a tutorial file and compile.\n"
"\n"
"### Web Audio\n"
"\n"
"A transpiled javascript version of the library is included in this repository, for both Script Processor Nodes and AudioWorklets. Try this out at (https://mimicproject.com/guides/maximJS). \n"
"\n"
"\n"
"### Mac OS XCode Project\n"
"\n"
"You can run the examples using the 'maximilianTest' XCode 3 project provided.\n"
"\n"
"\n"
"### MS Windows Visual Studio Project\n"
"\n"
"This is in the maximilianTestWindowsVS2010 folder. You will need to install the DirectX SDK, so that the program can use DirectSound.\n"
"\n"
"\n"
"### Command Line Compilation in Mac OS\n"
"\n"
"> g++ -Wall -D__MACOSX_CORE__ -o maximilian main.cpp RtAudio.cpp player.cpp maximilian.cpp -framework CoreAudio -framework CoreFoundation -lpthread\n"
"\n"
"> ./maximilian\n"
"\n"
"\n"
"### Command Line Compilation in Linux\n"
"\n"
"With OSS:\n"
"> g++ -Wall -D__LINUX_OSS__ -o maximilian main.cpp RtAudio.cpp player.cpp maximilian.cpp -lpthread\n"
"\n"
"With ALSA:\n"
"> g++ -Wall -D__LINUX_ALSA__ -o maximilian main.cpp RtAudio.cpp player.cpp maximilian.cpp -lasound -lpthread\n"
"\n"
"With Jack:\n"
"> g++ -Wall -D__UNIX_JACK__ -o maximilian main.cpp RtAudio.cpp player.cpp maximilian.cpp `pkg-config --cflags --libs jack` -lpthread\n"
"\n"
"then:\n"
"> ./maximilian\n"
"\n"
"\n"
"\n"
"### OpenFrameworks Project\n"
"\n"
"Maximilian works well with the OpenFrameworks C++ creative coding toolkit (http://www.openframeworks.cc).\n"
"\n"
"In the ofxMaxim directory you will find examples to run in Windows, OSX and iOS, including FFT analysis and granular synthesis.  \n"
"\n"
"You can install the ofxMaxim addon by copying the ofxMaxim/ofxMaxim folder into your openframeworks addons directory.\n"
"\n"
"Important: when using Maximilian on OSX, link against the Accelerate framework.\n"
"\n"
"\n";

const char* README_md = (const char*) temp_binary_data_0;


const char* getNamedResource (const char* resourceNameUTF8, int& numBytes)
{
    unsigned int hash = 0;

    if (resourceNameUTF8 != nullptr)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0x64791dc8:  numBytes = 3745; return README_md;
        default: break;
    }

    numBytes = 0;
    return nullptr;
}

const char* namedResourceList[] =
{
    "README_md"
};

const char* originalFilenames[] =
{
    "README.md"
};

const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8)
{
    for (unsigned int i = 0; i < (sizeof (namedResourceList) / sizeof (namedResourceList[0])); ++i)
    {
        if (namedResourceList[i] == resourceNameUTF8)
            return originalFilenames[i];
    }

    return nullptr;
}

}
