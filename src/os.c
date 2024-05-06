#include <liquid/os.h>

usize_t
last_error_message(errmsg_t buffer, usize_t buffer_size)
{
    return error_message(last_error_code(), buffer, buffer_size);
}