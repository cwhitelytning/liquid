#include <liquid/array-raw.h>
#include <liquid/exception.h>

void *
array_raw_copy(void *dest, const void *src, usize_t len)
{
    LIQUID_EXCEPTION_RAISE_IF_NOT(dest && src, nullptr,
                                  "invalid destination or source pointer")

    LIQUID_EXCEPTION_RAISE_IF(dest == src, nullptr,
                              "function does not support self-copying, "
                              "this is only allowed when using memmove")

    const uchar_t *l_src = (const uchar_t *)src;
    uchar_t       *l_dest = (uchar_t *)dest;

    while (len-- > 0)
    {
        *l_dest++ = *l_src++;
    }

    return l_dest;
}

const void *
array_raw_pos(const void *begin, const void *end, uchar_t value)
{
    const uchar_t *l_begin = (const uchar_t *)begin;
    const uchar_t *l_end = (const uchar_t *)end;

    while (l_begin != l_end && *l_begin != value)
    {
        ++l_begin;
    }
    return l_begin == l_end ? nullptr : (void *)l_begin;
}

const void *
array_raw_compare(const void *arr1_begin, const void *arr1_end,
                  const void *arr2_begin, const void *arr2_end)
{
    const uchar_t *arr1 = (const uchar_t *)arr1_begin;
    const uchar_t *arr2 = (const uchar_t *)arr2_begin;

    while (arr1 != arr1_end && arr2 != arr2_end)
    {
        if (*arr1 != *arr2)
        {
            return arr1;
        }
        arr1++;
        arr2++;
    }
    return nullptr;
}
