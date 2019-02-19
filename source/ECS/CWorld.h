#ifndef _CWORLD_H
#define _CWORLD_H

#include "Managers/CComponentManager.h"
#include "Managers/CEntityManager.h"
#include "CEntity.h"

namespace EphemeralEngine
{
  namespace Entities
  {

    struct CEntityHandler;

    /**
    * Class that manages the world.
    */
    class CWorld
    {
    private:
      CEntityManager* mpEntityManager; //!< Pointer to the entity manager.
      
    public:

      /**
      * Constructor of the class CWorld.
      */
      CWorld();

      /**
      * Deconstructor of the class CWorld.
      */
      ~CWorld();

      /**
      * Function that creates an entity.
      * @param CEntity -> Returns a new Entity.
      */
      CEntityHandler CreateEntity();

      /**
      * Template functions that allows us to add a component to an entity.
      * @param CEntity -> Entity where we want to add the component.
      * @param T -> Component that we want to add.
      */
      template<typename T>
      void AddComponent(const CEntity& aEntity, T& aComponent)
      {
        int j = 0;
      }

    };
  }
}

#endif // !_CWORLD_H

