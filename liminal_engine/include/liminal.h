#ifndef LIMINAL_ENGINE_LIMINAL_H
#define LIMINAL_ENGINE_LIMINAL_H

#include <stdbool.h>

#ifdef _WIN32
    #ifdef LE_EXPORTS
    #define LE_API __declspec(dllexport)
  #else
    #define LE_API __declspec(dllimport)
  #endif
#else
#define LE_API
#endif

LE_API void hello(void);
LE_API void init();
LE_API bool window_should_close();
LE_API void draw();
LE_API void shutdown();


#endif //LIMINAL_ENGINE_LIMINAL_H
