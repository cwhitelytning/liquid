#include <liquid/array-raw.h>
#include <liquid/exception.h>
#include <string.h>

void *
array_raw_copy(void *dest, const void *src, usize_t n)
{
    if (dest == src)
    {
        exception_raise("memcpy does not support self-copying, "
                        "this is only allowed when using memmove");

        return INVALID_POINTER;
    }

    memcpy(dest, src, n);
    return (char *)dest + n;
}