#ifndef _CENTITY_HANDLER
#define _CENTITY_HANDLER

#include "../CEntity.h"
#include "../CWorld.h"

namespace EphemeralEngine
{
  namespace Entities
  {
    struct CEntityHandler
    {
      CWorld* mpWorld; //!< Pointer to the world.
      CEntity mEntity; //!< Entity to handle.

      /**
      * Template functions that allows us to add a component to an entity.
      * @param CEntity -> Entity where we want to add the component.
      * @param T -> Component that we want to add.
      */
      template<typename T>
      void AddComponent(T& aComponent)
      {
        mpWorld->AddComponent<T>(mEntity, aComponent);
      }

      template<typename T>
      T GetComponent()
      {
        return mpWorld->GetComponent<T>(mEntity);
      }
    };
  }
}


#endif // !_CENTITY_HANDLER
