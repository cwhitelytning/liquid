#include <liquid/str.h>
#include <string.h>

usize_t
str_len(const char *dest)
{
    const void *end = array_raw_pos(dest, nullptr, '\0');
    return LIQUID_PTR_DIFF((void *)dest, end);
}

char *
str_raw_cpy(char *dest, usize_t dest_size, const char *src, usize_t src_size)
{
    if (!dest_size)
    {
        dest_size = str_len(dest);
    }

    if (!src_size)
    {
        src_size = str_len(src);
    }

    if (src_size > dest_size)
    {
        src_size = dest_size;
    }

    return array_raw_copy(dest, src, src_size);
}

wchar_t *
wstr_raw_cpy(wchar_t *dest, usize_t dest_size, const wchar_t *src,
             usize_t src_size)
{
    if (!dest_size)
    {
        dest_size = wcslen(dest);
    }

    if (!src_size)
    {
        src_size = wcslen(src);
    }

    if (src_size > dest_size)
    {
        src_size = dest_size;
    }

    return array_raw_copy(dest, src, src_size * sizeof(wchar_t));
}

char *
str_cpy(char *dest, usize_t dest_size, const char *src, usize_t src_size)
{
    char *ptr = str_raw_cpy(dest, dest_size, src, src_size);
    if (ptr)
    {
        *(ptr - 1) = '\0';
    }
    return ptr;
}

wchar_t *
wstr_cpy(wchar_t *dest, usize_t dest_size, const wchar_t *src, usize_t src_size)
{
    wchar_t *ptr = wstr_raw_cpy(dest, dest_size, src, src_size);
    if (ptr)
    {
        *(ptr - 1) = L'\0';
    }
    return ptr;
}