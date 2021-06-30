#ifndef WINDOW_h_
#define WINDOW_h_

#ifdef _WIN32
#include <Windows.h>
#elif __linux__
  
#else

#endif
  
struct window_t
{
  #define WIN_TITLE_BUF_SIZE 1024
  #ifdef _WIN32
  HWND 
  #elif __linux__
  
  #else 
  
  #endif
  window_handle;
};

#endif
