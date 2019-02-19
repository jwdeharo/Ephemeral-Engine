#include "../Utils/Utils.h"
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

    CEntity CWorld::CreateEntity()
    {
      return mpEntityManager->CreateEntity();
    }
  }
}