// sound.hpp
#if !defined(SOUND_HPP)
#define SOUND_HPP

#include <iostream>

void alutInit();

void loadSound(std::string fileName);

void playSound(std::string fileName, bool freeze);

void alutWrapUp();

#endif
