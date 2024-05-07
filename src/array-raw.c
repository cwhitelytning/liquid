#include <liquid/array-raw.h>
#include <liquid/exception.h>
#include <string.h>

void *
array_raw_copy(void *dest, const void *src, usize_t n)
{
    LIQUID_EXCEPTION_RAISE_IF_NOT(dest, nullptr, "invalid destination pointer");
    LIQUID_EXCEPTION_RAISE_IF_NOT(src, nullptr, "invalid source pointer");
    LIQUID_EXCEPTION_RAISE_IF(dest == src, nullptr,
                              "memcpy does not support self-copying, "
                              "this is only allowed when using memmove")

    memcpy(dest, src, n);
    return (uchar_t *)dest + n;
}

const void *
array_raw_pos(const void *begin, const void *end, uchar_t value)
{
    const uchar_t *ptr_begin = (const uchar_t *)begin;
    const uchar_t *ptr_end = (const uchar_t *)end;

    while (ptr_begin != ptr_end && *ptr_begin != value)
    {
        ++ptr_begin;
    }
    return ptr_begin == ptr_end ? nullptr : (void *)ptr_begin;
}