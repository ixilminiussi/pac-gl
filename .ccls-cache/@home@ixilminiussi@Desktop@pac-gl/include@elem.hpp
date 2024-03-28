// elem.hpp
#pragma once

#include "./vector.hpp"

class Elem {
    protected:
        Vector min, max;
    
    public:
        Elem(Vector min, Vector max) : min(min), max(max) {};
        virtual ~Elem() = default;
        virtual void render();
        virtual void update();
};
