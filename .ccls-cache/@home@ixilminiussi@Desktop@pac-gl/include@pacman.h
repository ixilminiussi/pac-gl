// pacman.h
#pragma once

#include "./elem.h"

class Pacman : Elem {
    Vector vel;
    float speed;

    public:
        Pacman(Vector pos, float speed);
        ~Pacman();
        void render() override;
        void update();
};
