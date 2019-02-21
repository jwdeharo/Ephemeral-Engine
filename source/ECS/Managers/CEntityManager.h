#ifndef _CENTITY_MANAGER_H
#define _CENTITY_MANAGER_H

#include "../CEntity.h"
#include <vector>

namespace EphemeralEngine
{
  namespace Entities
  {

    /**
    * Class CEntityManager will manage the alive entities of the world.
    */
    class CEntityManager
    {
    private:
      unsigned int mNumberEntities; //!< Total number of entities that are alive.
      std::vector<CEntity> mEntities; //!< Vector with the alive entities.

    public:
      /**
      * Constructor of the class CEntityManager.
      */
      CEntityManager();

      /**
      * Destructor of the class CEntityManager.
      */
      ~CEntityManager();

      /**
      * Function that creates an Entity with a Unique Id.
      * @return CEntity -> Entity with a unique id.
      */
      CEntity CreateEntity();

      /**
      * Function that destroys a given entity.
      * @param CEntity -> Entity to destroy.
      */
      void DestroyEntity(const CEntity& aEntity);

      /**
      * Function that checks if the given entity already exists.
      * @param CEntity -> Entity to check.
      */
      bool IsEntityAlive(const CEntity& aEntity) const;
    };
  }
}

#endif

