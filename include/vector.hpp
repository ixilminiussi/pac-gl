// vector.hpp
#if !defined(VECTOR_HPP)
#define VECTOR_HPP

// used to implement basic vector maths
struct Vector {
    float x, y, z;
    Vector(float x, float y, float z) : x(x), y(y), z(z){};
    Vector() : Vector(0, 0, 0) {};

    Vector(Vector const& vector) = default;
    ~Vector() = default;

    Vector& operator=(Vector const& v) = default;

    Vector operator-() const {
        return Vector(-x,-y,-z);
    }

    void operator+=(Vector const& v) {
        x += v.x;
        y += v.y;
        z += v.z;
    }

    void operator/=(float f) {
        x /= f;
        y /= f;
        z /= f;
    }

    void operator*=(float f) {
        x *= f;
        y *= f;
        z *= f;
    }

    void operator-=(Vector const& v) {
        *this += -v;
    }
};

inline Vector operator+(Vector const& v1, Vector const& v2) {
  Vector v(v1);
  v += v2;
  return v;
}

inline Vector operator-(Vector const& v1, Vector const& v2) {
  Vector v(v1);
  v -= v2;
  return v;
}

inline Vector operator*(Vector const& v1, float f) {
  Vector v(v1);
  v *= f;
  return v;
}

inline Vector operator*(float f, Vector const& v1) {
  return v1*f;
}

#endif
