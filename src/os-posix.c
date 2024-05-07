#include <errno.h>
#include <liquid/nullptr.h>
#include <liquid/os-posix.h>
#include <liquid/str.h>
#include <string.h>

errcode_t
last_error_code()
{
    return errno;
}

usize_t
error_message(errcode_t code, errmsg_t buffer, usize_t buffer_size)
{
    const errchar_t *msg = strerror(code);
    return msg ? LIQUID_PTR_DIFF(msg, str_cpy(buffer, buffer_size, msg, 0)) : 0;
}

void
set_last_error_code(errcode_t code)
{
    errno = code;
}