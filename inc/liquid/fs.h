#ifndef LIQUID_FS_H
#define LIQUID_FS_H

#if defined(LIQUID_TARGET_OS_WINDOWS)
    #include "fs-windows.h"
#elif defined(LIQUID_TARGET_OS_LINUX)
    #include "fs-linux.h"
#elif defined(LIQUID_TARGET_OS_DARWIN)
    #include "fs-darwin.h"
#else
    #error "Unsupported OS for file system"
#endif

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // LIQUID_FS_H
