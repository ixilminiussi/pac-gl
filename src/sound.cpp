// sound.cpp
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alut.h>
#include <stdio.h>
#include <iostream>

#include "../include/sound.hpp"

ALuint buffer, source;
ALint state;
std::string currentlyLoadedFile;

void alutInit() {
    alutInit(0, NULL);
    alGetError();
}

void loadSound(std::string fileName) {
    buffer = alutCreateBufferFromFile(fileName.c_str());
    alGenSources(1, &source);
    alSourcei(source, AL_BUFFER, buffer);
    currentlyLoadedFile = fileName;
}

void playSound(std::string fileName, bool freeze) { // using the "AL_SOURCE_STATE" seems to create a small delay between the end of one sound and the start of another, making a timer lets us better control
    if (fileName.compare(currentlyLoadedFile)) {
        loadSound(fileName);
    }
    alGetSourcei(source, AL_SOURCE_STATE, &state); // only play if previous sound has finished (it seems this is how it was handled in original game)
    if (state == AL_PLAYING) return;
    alSourceRewind(source);
    alSourcePlay(source);

    if (freeze) {
        do {
            alGetSourcei(source, AL_SOURCE_STATE, &state); // only play if previous sound has finished (it seems this is how it was handled in original game)
        } while (state == AL_PLAYING);
    }
}

void alutWrapUp() {
    alDeleteSources(1, &source);
    alDeleteBuffers(1, &buffer);

    alutExit();
}
