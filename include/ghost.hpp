// ghost.hpp
#pragma once

#include "./vector.hpp"
#include "./cube.hpp"

class Ghost : public Cube {
    private:
        Vector* regularColor;
        Vector* altColor = new Vector(0.13f, 0.13f, 1.0f);
        DIRECTION dir = NONE;
        Vector vel;
        Vector respawnPos = Vector(-0.7f, -0.1f, 0.0f);
        float speed = 0.08f;
        float altSpeed = 0.06f;
        float iq;
        int leewayTime = 8; // used for the opposite purpose here
        int leewayTimer = 0;
        std::vector<DIRECTION> possibilities;
        int deadFrame = 0; // if 0, not in use, else, displays whichever score is held in int
        DIRECTION pickDirection();
        void turn(DIRECTION newDir);
        bool atIntersection();

    public:
        bool vulnerable = false;
        Ghost(Vector pos, Vector* color, float iq);
        ~Ghost() = default;
        void update();
        void render();
        void die(int score);
        void respawn();
};
