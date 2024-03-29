// sound.hpp
#pragma once

#include <iostream>

void alutInit();

void loadSound(std::string fileName);
void playSound(std::string fileName, float duration);

void alutWrapUp();
