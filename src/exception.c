#include <liquid/exception.h>

exception_handler_fn *m_handler = nullptr;

void
exception_raise(const errmsg_t message, ...)
{
    if (m_handler)
    {
        va_list args;
        va_start(args);
        m_handler(message, &args);
        va_end(args);
    }
}

exception_handler_fn *
exception_set_handler(exception_handler_fn *handler)
{
    exception_handler_fn *prev = m_handler;
    m_handler = handler;
    return prev;
}