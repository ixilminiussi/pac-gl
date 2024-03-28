// wait.cpp
#pragma once

#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__) // windows
  #include <windows.h>

  inline void wait(unsigned long ms) { Sleep(ms); }

#else // posix
  #include <unistd.h>

  inline void wait( unsigned long ms ) { usleep( ms * 1000 ); }

#endif
