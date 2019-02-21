#ifndef _ISYSTEM_H
#define _ISYSTEM_H

namespace EphemeralEngine
{
  namespace Entities
  {
    /**
    * Interface that all systems need to implement.
    */
    class ISystem
    {
    public:

      /**
      * Function that will init the necessary data of the system.
      */
      virtual void Init() = 0;

      /**
      * Method called every frame.
      */
      virtual void Update(const float aDeltaTime) = 0;
    };
  }
}

#endif // !_ISYSTEM_H