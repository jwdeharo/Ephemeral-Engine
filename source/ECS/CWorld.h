#ifndef _CWORLD_H
#define _CWORLD_H

#include "Managers/CComponentManager.h"
#include "Managers/CEntityManager.h"
#include "CEntity.h"

#include <vector>

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
      std::vector<CBaseComponentManager*> mComponentManagers;

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
        CComponentManager<T>* Manager = GetComponentManager<T>();
        Manager->AddComponent(aEntity, aComponent);
        std::string s = "";
      }

      template<typename T>
      T GetComponent(const CEntity& aEntity)
      {
        CComponentManager<T>* Manager = GetComponentManager<T>();
        return Manager->GetComponent(aEntity);
      }

      template<typename T>
      CComponentManager<T>* GetComponentManager()
      {
        unsigned int Family = GetComponentFamily<T>();

        if (Family >= mComponentManagers.size())
        {
          mComponentManagers.resize(Family + 1);
        }

        if (mComponentManagers[Family] == nullptr)
        {
          mComponentManagers[Family] = new CComponentManager<T>();
        }

        return static_cast<CComponentManager<T>*>(mComponentManagers[Family]);
      }

    };
  }
}

#endif // !_CWORLD_H

