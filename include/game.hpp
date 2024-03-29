// game.hpp
#if !defined(GAME_HPP)
#define GAME_HPP

#include <GL/freeglut.h>
#include <vector>

#include "vector.hpp"
#include "pacman.hpp"
#include "ghost.hpp"
#include "cube.hpp"

class Labyrinth {
    private:
        Labyrinth() {};

        bool starting, restarting, ending;
        unsigned int lives = 3;
        unsigned int score = 0;
        const float depth = -30.0f;
        float poweredTime = 1250;
        float poweredTimer = 0;


        void populateArea(Vector min, Vector max);

    public:
        static Labyrinth& getInstance() {
            static Labyrinth instance; // Guaranteed to be destroyed.
            return instance;
        }

        Labyrinth(Labyrinth const&) = delete;
        void operator=(Labyrinth const&) = delete;

        Pacman pacman;
        std::vector<Cube> walls;
        std::vector<Pellet> pellets;
        std::vector<Ghost> ghosts;

        void restart();
        void start();
        void init();
        void update();
        void render();
        void powerup();
        bool shootRay(Cube rayCube, DIRECTION dir, float dist);
        void onKeyInput(int key);
        void display();
        void onReshape(GLsizei width, GLsizei height);
        void endGame();
        void checkWin();
};

#endif
