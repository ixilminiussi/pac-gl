// coin.hpp
#pragma once

#include "./vector.hpp"

struct Box {
    protected:
        Vector pos, size;

    public:
        Box(Vector pos, Vector size) : pos(pos), size(size) {};
        virtual ~Box() = default;

        bool overlaps(Vector min, Vector max);
};

