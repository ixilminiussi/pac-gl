// vector.hpp
#if !defined(VECTOR_HPP)
#define VECTOR_HPP

// used to implement basic vector maths
struct Vector {
    float x, y, z;
    Vector(float x, float y, float z) : x(x), y(y), z(z){};
    Vector() : Vector(0, 0, 0) {};

    ~Vector() = default;

    Vector plus(Vector toAdd) {
        return Vector(x + toAdd.x, y + toAdd.y, z + toAdd.z);
    };

    Vector minus(Vector toSub) {
        return Vector(x - toSub.x, y - toSub.y, z - toSub.z);
    };

    Vector divBy(float toDiv) {
        return Vector(x / toDiv, y / toDiv, z / toDiv);
    };

    Vector mulBy(float toMul) {
        return Vector(x * toMul, y * toMul, z * toMul);
    };
};

#endif
