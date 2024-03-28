// wall.hpp
#pragma once

#include "./elem.hpp"

class Wall : Elem {
    int size;

    private:
        Wall(Vector pos, int size) : Elem(pos), size(size) {};
        ~Wall() = default;
        void update() override {};

        void render() override;
};
