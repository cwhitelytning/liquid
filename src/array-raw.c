#include <liquid/array-raw.h>
#include <liquid/exception.h>
#include <string.h>

void *
array_raw_copy(void *dest, const void *src, usize_t n)
{
    LIQUID_EXCEPTION_RAISE_IF(dest == src, INVALID_POINTER,
                              "memcpy does not support self-copying, "
                              "this is only allowed when using memmove");

    memcpy(dest, src, n);
    return (char *)dest + n;
}