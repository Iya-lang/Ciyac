#ifndef PLATFORM_H
#define PLATFORM_H

#if defined (_WIN32) || defined (_WIN64)
    #define PLATFORM_WINDOWS 1
    #define PATH_SEPERATOR '\\'
#elif defined (__linux__)
    #define PLATFORM_LINUX 1
    #define PATH_SEPERATOR '/'
#elif defined (__APPLE__) || defined(__MACH__)
    #define PLATFORM_MACOS 1
    #define PATH_SEPERATOR '/'
#endif

#endif
