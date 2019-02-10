// Global settings
#define _CRT_SECURE_NO_WARNINGS     // Don't warn about using fopen..
#define WIN32_LEAN_AND_MEAN         // Reduce the size of things included in windows.h
#define _USE_MATH_DEFINES           // M_PI M_PI_2

// C/C++
#include <cstdio>
#include <cstdarg>
#include <windows.h>

#include "Utils.h"
namespace EphemeralEngine
{
  namespace Utils
  {
    void dbg(const char* format, ...) 
    {
#ifdef _DEBUG
      va_list argptr;
      va_start(argptr, format);
      char dest[1024 * 16];
      _vsnprintf(dest, sizeof(dest), format, argptr);
      va_end(argptr);
      ::OutputDebugString(dest);
#endif

    }

    bool fatal(const char* format, ...) 
    {
      va_list argptr;
      va_start(argptr, format);
      char dest[1024 * 16];
      _vsnprintf(dest, sizeof(dest), format, argptr);
      va_end(argptr);
      ::OutputDebugString(dest);
      MessageBox(nullptr, dest, "Error!", MB_OK);
      return false;
    }
  }
}