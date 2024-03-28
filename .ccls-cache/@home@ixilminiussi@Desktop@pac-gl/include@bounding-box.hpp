//bounding-box.hpp
#pragma once

#include "./elem.hpp"
#include "./vector.hpp"

class BoundingBox {
    Vector min, max;

    BoundingBox(Vector min, Vector max) : min(min), max(max) {};
};
