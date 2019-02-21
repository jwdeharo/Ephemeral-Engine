
#include "CEntityManager.h"

namespace EphemeralEngine
{
  namespace Entities
  {
    CEntityManager::CEntityManager()
    {
      mNumberEntities = 0;
    }

    CEntityManager::~CEntityManager()
    {
      for (auto& mEntity : mEntities)
      {
        DestroyEntity(mEntity);
      }
    }

    CEntity CEntityManager::CreateEntity()
    {
      mNumberEntities++;
      CEntity NewEntity = { mNumberEntities };

      //We make sure the entity that we want to create does not share any id with another entity.
      while (IsEntityAlive(NewEntity))
      {
        mNumberEntities++;
      }

      return NewEntity;
    }

    void CEntityManager::DestroyEntity(const CEntity& aEntity)
    {

    }

    bool CEntityManager::IsEntityAlive(const CEntity& aEntity) const
    {
      return std::find(mEntities.begin(), mEntities.end(), aEntity) != mEntities.end();
    }
  }
}