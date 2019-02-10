#include "Math/Vector3.h"
#include "Utils/Utils.h"

int main()
{
  using namespace EphemeralEngine;

  Maths::Vector3 A(3.f, 5.f, 7.f);
  Maths::Vector3 B(11.f, 13.f, 17.f);
  

  Utils::dbg("Vector is %f %f %f", A.Cross(B).x, A.Cross(B).y, A.Cross(B).z);

  return -1;
}