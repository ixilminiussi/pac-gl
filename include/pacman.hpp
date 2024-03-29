// pacman.hpp
#pragma once

#include "vector.hpp"
#include "cube.hpp"
#include "ghost.hpp"
#include <AL/al.h>
#include <AL/alc.h>

float poweredTimer;
float poweredTime = 1250; 

class Pacman : public Cube {
    private:
        DIRECTION goalDir = NONE;
        Vector vel;
        DIRECTION dir = NONE;
        int multiplier = 1; // used to multiply reward from eating ghosts (as per official rules)
        int leewayTime = 32;
        int leewayTimer;
        float speed = 0.06f;
        void (*restart)(void);

        void tryTurn();
        void die();

    public:
        int score = 0;

        Pacman(Vector pos, void (*restart)(void));
        ~Pacman() = default;
        void update();
        void goLeft();
        void goRight();
        void goUp();
        void goDown();
};
