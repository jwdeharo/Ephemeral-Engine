#ifndef VECTOR_3_H
#define VECTOR_3_H

class Vector3
{
private:
  float x;
  float y;
  float z;

public:
  Vector3() :
    x(0.f),
    y(0.f),
    z(0.f)
  {

  }

  Vector3(const float _x, const float _y, const float _z) :
    x(_x),
    y(_y),
    z(_z)
  {

  }

  Vector3(const Vector3& aOther)
  {
    *this = aOther;
  }

};

#endif