#ifndef _CCOMPONENT_MANAGER_H
#define _CCOMPONENT_MANAGER_H

#include "../CComponent.h"
#include <map>

namespace EphemeralEngine
{
  namespace Entities
  {
    class CBaseComponentManager
    {
    public:
      CBaseComponentManager() = default;
      virtual ~CBaseComponentManager() = default;
      CBaseComponentManager(const CBaseComponentManager &) = default;
      CBaseComponentManager &operator=(const CBaseComponentManager &) = default;
      CBaseComponentManager(CBaseComponentManager &&) = default;
      CBaseComponentManager &operator=(CBaseComponentManager &&) = default;
    };

    struct CEntity;
   
    template<typename ComponentType>
    class CComponentManager : public CBaseComponentManager
    {
    private:
      SComponentData<ComponentType> mComponentInstance;
      std::map<CEntity, unsigned int> mEntityMap;
    public:
      CComponentManager()
      {
        mComponentInstance.Data = static_cast<std::array<ComponentType, 1024> *>(malloc(sizeof(ComponentType) * 1024));
      }

      void AddComponent(const CEntity& aEntity, ComponentType& aComponent)
      {
        if (mEntityMap.find(aEntity) != mEntityMap.end())
        {
          Utils::fatal("Entity already has this component.");
          return;
        }
        unsigned int ComponentInstance = mComponentInstance.Size;
        mComponentInstance.Data->at(ComponentInstance) = aComponent;
        mComponentInstance.Size++;
        mEntityMap[aEntity] = ComponentInstance;
      }

      ComponentType GetComponent(const CEntity& aEntity)
      { 
        unsigned int ComponentInstance = mEntityMap[aEntity];

        return mComponentInstance.Data->at(ComponentInstance);
      }
    };
  }
}

#endif // !_CCOMPONENT_MANAGER_H

