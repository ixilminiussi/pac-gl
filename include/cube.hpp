// cube.hpp
#if !defined(CUBE_HPP)
#define CUBE_HPP

#include "vector.hpp"
#include <vector>

enum DIRECTION { NONE, UP, LEFT, DOWN, RIGHT };

// used for rendering
struct Cube {
    Vector* color;

    Vector pos, size;

    Cube(Vector pos, Vector size);
    ~Cube() = default;
    void render();
    bool overlaps(Cube *cube);
};

struct Pellet : Cube {
    bool picked = false;

    Pellet(Vector pos);
    ~Pellet() = default;
    void render();
    virtual int pickup();
};

struct PowerUp : Pellet {
    PowerUp(Vector pos);
    ~PowerUp() = default;
    int pickup() override;
};

bool shootRay(Cube rayCube, DIRECTION dir, float dist);
DIRECTION getOpposite(DIRECTION dir);
std::pair<DIRECTION, DIRECTION> getSides(DIRECTION dir);
#endif
