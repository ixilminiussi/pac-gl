// coin.hpp
#pragma once

#include "./cube.hpp"

class Coin : Cube {
    public: 
        Coin(Vector pos) : Cube(Vector(1.0f, 1.0f, 0.0f), pos, Vector(0.2f, 0.2f, 0.2f)) {};
        ~Coin() = default;
        void render();
        void pickup();
};
