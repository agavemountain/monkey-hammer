#pragma once

#if defined (USE_WINDOWS_DLL_SEMANTICS) || defined (WIN32)
    #ifdef _MSC_VER
        #pragma warning(disable : 4251)
    #endif // _MSC_VER

    #ifdef USE_IMPORT_EXPORT
        #ifdef MONKEY_CORE_EXPORTS
            #define  MKY_CORE_API __declspec(dllexport)
        #else // MONKEY_CORE_EXPORTS
            #define  MKY_CORE_API __declspec(dllimport)
        #endif // MONKEY_CORE_EXPORTS
    #else // USE_IMPORT_EXPORT
        #define MKY_CORE_API
    #endif // USE_IMPORT_EXPORT
#else // defined (USE_WINDOWS_DLL_SEMANTICS) || defined (WIN32)
    #define MKY_CORE_API
#endif // defined (USE_WINDOWS_DLL_SEMANTICS) || defined (WIN32)

