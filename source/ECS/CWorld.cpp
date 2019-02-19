#include "../Utils/Utils.h"
#include "Handlers/CEntityHandler.h"
#include "CWorld.h"

namespace EphemeralEngine
{
  namespace Entities
  {
    CWorld::CWorld()
    {
      mpEntityManager = new CEntityManager();
    }

    CWorld::~CWorld()
    {
      SAFE_DELETE(mpEntityManager);
    }

    CEntityHandler CWorld::CreateEntity()
    {
      return { this , mpEntityManager->CreateEntity() };
    }
  }
}