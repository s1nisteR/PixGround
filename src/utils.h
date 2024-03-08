#ifndef UTILS_H
#define UTILS_H

#include <iostream>

inline void logError() { std::cout << SDL_GetError() << std::endl; }
inline void log(const char* message) { std::cout << message << std::endl; }

#endif