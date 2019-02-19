#ifndef _CWORLD_H
#define _CWORLD_H

#include "Managers/CComponentManager.h"
#include "Managers/CEntityManager.h"
#include "CEntity.h"

namespace EphemeralEngine
{
  namespace Entities
  {

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
      CEntity CreateEntity();

    };
  }
}

#endif // !_CWORLD_H

