#ifndef _ISYSTEM_H
#define _ISYSTEM_H

namespace EphemeralEngine
{
  namespace Entities
  {
    class ISystem
    {
    public:
      virtual void Update(float aDeltaTime) = 0;
      virtual void Init() = 0;
    };
  }
}

#endif