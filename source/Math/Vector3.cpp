#include "Vector3.h"
#include <math.h>

namespace EphemeralEngine
{
  namespace Maths
  {
    Vector3::Vector3() :
      x(0.f),
      y(0.f),
      z(0.f)
    {

    }

    Vector3::Vector3(const float _x, const float _y, const float _z) :
      x(_x),
      y(_y),
      z(_z)
    {

    }

    Vector3::Vector3(const Vector3& aOther)
    {
      *this = aOther;
    }

    float Vector3::Length() const
    {
      return sqrtf(powf(x, 2.f) + powf(y, 2.f) + powf(z, 2.f));
    }

    float Vector3::SquaredLength() const
    {
      return sqrtf(Dot());
    }

    float Vector3::Dot() const
    {
      return pow(x, 2.f) + pow(y, 2.f) + pow(z, 2.f);
    }

    float Vector3::Dot(const Vector3& aOther) const
    {
      return x * aOther.x + y * aOther.y + z * aOther.z;
    }

    Vector3 Vector3::Cross(const Vector3 aOther) const
    {
      return Vector3(y * aOther.z - z * aOther.y, z * aOther.x - x * aOther.z, x * aOther.y - y * aOther.x);
    }

    Vector3 Vector3::Subtract(const Vector3& aOtherA, const Vector3& aOtherB)
    {
      Vector3 Result = aOtherA;
      Result -= aOtherB;

      return Result;
    }

    Vector3 Vector3::Add(const Vector3& aOtherA, const Vector3& aOtherB)
    {
      Vector3 Result = aOtherA;
      Result += aOtherB;

      return Result;
    }

    Vector3 Vector3::Lerp(const Vector3& aStart, const Vector3& aEnd, const float aPercent)
    {
      return (Add(aStart, (Subtract(aEnd, aStart) * aPercent)));
    }

    void Vector3::Normalize()
    {
      *this = Vector3(x / Length(), y / Length(), z / Length());
    }

    Vector3& Vector3::operator*= (const float aScalar)
    {
      x *= aScalar;
      y *= aScalar;
      z *= aScalar;

      return *this;
    }

    Vector3& Vector3::operator* (const float aScalar)
    {
      x *= aScalar;
      y *= aScalar;
      z *= aScalar;

      return *this;
    }

    Vector3& Vector3::operator+ (const Vector3& aOther)
    {
      x += aOther.x;
      y += aOther.y;
      z += aOther.z;

      return *this;
    }

    Vector3& Vector3::operator+= (const Vector3& aOther)
    {
      x += aOther.x;
      y += aOther.y;
      z += aOther.z;

      return *this;
    }

    Vector3& Vector3::operator- (const Vector3& aOther)
    {
      x -= aOther.x;
      y -= aOther.y;
      z -= aOther.z;

      return *this;
    }

    Vector3& Vector3::operator-= (const Vector3& aOther)
    {
      x -= aOther.x;
      y -= aOther.y;
      z -= aOther.z;

      return *this;
    }
  }
}