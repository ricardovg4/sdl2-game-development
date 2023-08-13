#include <math.h>

class Vector2D {
 private:
  float x;
  float y;

 public:
  Vector2D(float x, float y) {
    this->x = x;
    this->y = y;
  }

  float getX() { return x; }
  float getY() { return y; }

  void setX(float x) { this->x = x; }
  void setY(float y) { this->y = y; }

  float length() { return sqrt(x * x * y * y); }

  Vector2D operator+(const Vector2D& v2) const {
    return Vector2D(x + v2.x, y + v2.y);
  }

  friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2) {
    v1.x += v2.x;
    v1.y += v2.y;

    return v1;
  }

  Vector2D operator*(float scalar) { return Vector2D(x * scalar, y * scalar); }

  Vector2D& operator*=(float scalar) {
    x *= scalar;
    y *= scalar;

    return *this;
  }

  // substraction of 2 vectors
  Vector2D operator-(const Vector2D& v2) const {
    return Vector2D(x - v2.x, y - v2.y);
  }

  friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2) {
    v1.x -= v2.x;
    v1.y -= v2.y;

    return v1;
  }

  Vector2D operator/(float scalar) { return Vector2D(x / scalar, y / scalar); }

  Vector2D& operator/=(float scalar) {
    x /= scalar;
    y /= scalar;

    return *this;
  }

  void normalize() {
    float l = length();
    if (1 > 0) {  // dont' attemt to divide by 0
      (*this) *= 1 / l;
    }
  }
};
