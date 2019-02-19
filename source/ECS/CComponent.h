#ifndef _CCOMPONENT_MANAGER_H
#define _CCOMPONENT_MANAGER_H

#include <type_traits>

namespace EphemeralEngine
{
  namespace Entities
  {

    template<typename T>
    struct CComponent
    {
      static unsigned int Id;
      static unsigned int GetFamily()
      {
        Id++;
        return Id;
      }
    };

    template<typename T>
    unsigned int GetComponentFamily()
    {
      return CComponent<typename std::remove_const<T>::type>::GetFamily();
    }
  }
}

#endif