// map.cpp
#pragma once

#include <vector>
#include "cube.cpp"

std::vector<Cube*> generateWalls() {
    std::vector<Cube*> walls;
    const Vector wallColor = Vector(0.0f, 1.0f, 1.0f);

    walls.push_back(new Cube(wallColor, Vector(-7.0f, -8.0f, 0.0f), Vector(1.0f, 16.0f, 1.0f)));
    walls.push_back(new Cube(wallColor, Vector(-7.0f, 8.0f, 0.0f), Vector(14.0f, 1.0f, 1.0f)));
    walls.push_back(new Cube(wallColor, Vector(-7.0f, -9.0f, 0.0f), Vector(14.0f, 1.0f, 1.0f)));
    walls.push_back(new Cube(wallColor, Vector(-7.0f, -8.0f, 0.0f), Vector(1.0f, 16.0f, 1.0f)));
    
    return walls;
}
