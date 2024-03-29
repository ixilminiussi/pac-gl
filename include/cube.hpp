// cube.hpp
#if !defined(CUBE_HPP)
#define CUBE_HPP

#include "vector.hpp"
#include <vector>

enum DIRECTION { NONE, UP, LEFT, DOWN, RIGHT };

// used for rendering
class Cube {
    protected:
        Vector* color;

    public: 
        Vector pos, size;

        Cube(Vector const& pos, Vector const& size);
        ~Cube() = default;
        void render() const;
        bool overlaps(Cube const& cube) const;
};

class Pellet : public Cube {
    public:
        unsigned int flag; // 0 for pellet, 1 for powerup
        Pellet(Vector const& pos, unsigned int flag);
        ~Pellet() = default;
};

DIRECTION getOpposite(DIRECTION dir);
std::pair<DIRECTION, DIRECTION> getSides(DIRECTION dir);
#endif
