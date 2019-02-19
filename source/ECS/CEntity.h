#ifndef _CENTITY_H
#define _CENTITY_H

namespace EphemeralEngine
{
  namespace Entities
  {
    /**
    * An Entity is just a unique Id. No logic, anything.
    */
    struct CEntity
    {
      unsigned int Id; //!< Id that identifies each entity.

      /**
      * Overload of the operator ==.
      */
      friend bool operator==(const CEntity& aEntityLeft, const CEntity& aEntityRight) { return aEntityLeft.Id == aEntityRight.Id; };
      friend bool operator<(const CEntity &l, const CEntity &r) { return l.Id < r.Id; }
    };
  }
}

#endif