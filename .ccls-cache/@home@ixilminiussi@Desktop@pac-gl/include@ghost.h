// ghost.h
#pragma once

#include "./elem.h"

class Ghost : Elem {
    Vector vel;
    float probability;
    float speed;

    public:
        Ghost(Vector pos, float speed, float probability);
        ~Ghost();
        void render() override;
        void update();
};
