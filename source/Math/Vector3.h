#ifndef VECTOR_3_H
#define VECTOR_3_H

namespace EphemeralEngine
{
  namespace Maths
  {
    /**
    * Struct Vector3 will help us doing some vector operations.
    */
    struct Vector3
    {
      float x; //!< X coordinate.
      float y; //!< Y coordinate.
      float z; //!< Z coordinate.

      /**
      * Default constructor, will init all to 0.f.
      */
      Vector3();

      /**
      * Vector3 Constructor, will copy another Vector3 data.
      * @param aOther: the vector3 to copy.
      */
      Vector3(const Vector3& aOther);

      /**
      * Vector3 constructor. Will init vars with the ones in the params.
      * @param _x: new x.
      * @param _y: new y.
      * @param _z: new z.
      */
      explicit Vector3(const float _x, const float _y, const float _z);

      float Length() const;
      float SquaredLength() const;
      float Dot() const;
      float Dot(const Vector3& aOther) const;
      Vector3 Cross(const Vector3 aOther) const;

      Vector3 Lerp(const Vector3& aStart, const Vector3& aEnd, const float aPercent);
      Vector3 Subtract(const Vector3& aOtherA, const Vector3& aOtherB);
      Vector3 Add(const Vector3& aOtherA, const Vector3& aOtherB);

      void Normalize();
      

      Vector3& operator*= (const float aScalar);
      Vector3& operator* (const float aScalar);

      Vector3& operator+ (const Vector3& aOther);
      Vector3& operator+= (const Vector3& aOther);
      Vector3& operator- (const Vector3& aOther);
      Vector3& operator-= (const Vector3& aOther);
    };
  }
}

#endif