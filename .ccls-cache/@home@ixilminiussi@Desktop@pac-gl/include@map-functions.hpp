// map-functions.hpp
#pragma once

#include <vector>
#include "./cube.hpp"

void generateWalls(std::vector<Cube*> *walls);

void generateCoins(std::vector<Cube*> *coins);

void populateArea(Vector min, Vector max);
