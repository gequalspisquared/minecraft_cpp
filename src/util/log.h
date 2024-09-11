#pragma once

#include <iostream>

#ifdef NDEBUG /* Release mode */
    #define LOG_INFO(content)
    #define LOG_WARNING(content)
    #define LOG_ERROR(content)
#else /* Debug mode */
    #define LOG_INFO(content)    do { std::cerr << "INFO: "    << content << "\n"; } while(0)
    #define LOG_WARNING(content) do { std::cerr << "WARNING: " << content << "\n"; } while(0)
    #define LOG_ERROR(content)   do { std::cerr << "ERROR: "   << content << "\n"; } while(0)
#endif
