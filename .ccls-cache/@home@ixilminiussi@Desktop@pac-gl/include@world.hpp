// world.hpp
#pragma once

#include "./cube.hpp"

const Vector coinColor = Vector(1.0f, 1.0f, 0.0f);

struct Coin : Cube {
    Coin(Vector pos) : Cube(coinColor, pos, Vector(0.2f, 0.2f, 0.2f)) {};
    ~Coin() = default;
    void pickup();
};

const Vector wallColor = Vector(0.0f, 1.0f, 1.0f);

struct Wall : Cube {
    Wall(Vector pos, Vector size) : Cube(wallColor, pos, size) {}
    ~Wall() = default;
};
