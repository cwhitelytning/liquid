#include <liquid/nullptr.h>
#include <liquid/os-windows.h>
#include <windows.h>

errcode_t
last_error_code()
{
    return GetLastError();
}

void
set_last_error_code(errcode_t code)
{
    SetLastError(code);
}

usize_t
error_message(errcode_t code, errmsg_t buffer, usize_t buffer_size)
{
    return FormatMessage(
        FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, nullptr,
        code, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), buffer, buffer_size,
        nullptr);
}

handle_t
cur_proc()
{
    return GetCurrentProcess();
}