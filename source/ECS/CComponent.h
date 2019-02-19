#ifndef _CCOMPONENT_H
#define _CCOMPONENT_H

#include <type_traits>
#include <array>

namespace EphemeralEngine
{
  namespace Entities
  {

    template<typename T>
    struct SComponentData
    {
      unsigned int Size = 1;
      std::array<T, 1024> *Data;
    };

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