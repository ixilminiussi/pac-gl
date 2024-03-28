// elem.h
#pragma once

#include "./vector.h"

class Elem {
    Vector pos;
    
    public:
        Elem(Vector pos);
        ~Elem();
        virtual void render();
        void update();
};
