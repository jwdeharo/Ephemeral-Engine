#ifndef _CCOMPONENT_MANAGER_H
#define _CCOMPONENT_MANAGER_H

#include "../CComponent.h"
#include <unordered_map>

namespace EphemeralEngine
{
  namespace Entities
  {
    struct CEntity;
   
    template<typename ComponentType>
    class CComponentManager
    {
    private:
      SComponentData<ComponentType> mComponentInstance;
      std::unordered_map<CEntity, unsigned int> mEntityMap;
    public:
      void AddComponent(const CEntity& aEntity, ComponentType& aComponent)
      {
        unsigned int ComponentInstance = mComponentInstance.Size;
        mComponentInstance.Data->at(ComponentInstance) = aComponent;
        mComponentInstance.Size++;
        mEntityMap[aEntity] = ComponentInstance;
      }
    };
  }
}

#endif // !_CCOMPONENT_MANAGER_H

