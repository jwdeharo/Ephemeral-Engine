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

    struct ComponentCounter
    {
      static int Counter;
    };

    template<typename T>
    struct SComponent
    {
      static  int GetFamily()
      {
        static int Family = ComponentCounter::Counter++;
        return Family;
      }
    };

    template<typename T>
    static int GetComponentFamily()
    {
      return SComponent<typename std::remove_const<T>::type>::GetFamily();
    }
  }
}

#endif