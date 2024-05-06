#include <liquid/array-raw.h>
#include <string.h>

void *
array_raw_copy(void *dest, const void *src, usize_t n)
{
    memcpy(dest, src, n);
    return (char *)dest + n;
}