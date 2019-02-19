#ifndef UTILS_H
#define UTILS_H

#define SAFE_DELETE(a) if( (a) != nullptr ) delete (a); (a) = nullptr;

namespace EphemeralEngine
{
  namespace Utils
  {
    void dbg(const char* fmt, ...);
    bool fatal(const char* fmt, ...);
  }
}

#endif