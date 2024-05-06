#include <liquid/str.h>
#include <string.h>

char *
str_raw_cpy(char *dest, usize_t dest_size, const char *src, usize_t src_size)
{
    if (!dest_size)
    {
        dest_size = strlen(src);
    }

    if (!src_size)
    {
        src_size = strlen(src);
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
        dest_size = wcslen(src);
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
    *ptr = '\0';
    return ptr;
}

wchar_t *
wstr_cpy(wchar_t *dest, usize_t dest_size, const wchar_t *src, usize_t src_size)
{
    wchar_t *ptr = wstr_raw_cpy(dest, dest_size, src, src_size);
    *ptr = L'\0';
    return ptr;
}