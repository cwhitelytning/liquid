#include <liquid/str.h>
#include <string.h>

uoffset_t
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

    array_raw_copy(dest, src, src_size);
    return src_size;
}

uoffset_t
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

    array_raw_copy(dest, src, src_size * sizeof(wchar_t));
    return src_size;
}

uoffset_t
str_cpy(char *dest, usize_t dest_size, const char *src, usize_t src_size)
{
    const uoffset_t offset = str_raw_cpy(dest, dest_size, src, src_size);
    if (offset)
    {
        dest[offset - 1] = '\0';
    }
    return offset;
}

uoffset_t
wstr_cpy(wchar_t *dest, usize_t dest_size, const wchar_t *src, usize_t src_size)
{
    const uoffset_t offset = wstr_raw_cpy(dest, dest_size, src, src_size);
    if (offset)
    {
        dest[offset - 1] = L'\0';
    }
    return offset;
}