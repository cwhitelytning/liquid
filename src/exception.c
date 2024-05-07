#include <liquid/exception.h>

exception_handler_fn *m_handler = nullptr;

usize_t
exception_raise(const errmsg_t message, usize_t len)
{
    return m_handler ? m_handler(message, len) : 0;
}

void
exception_set_handler(exception_handler_fn *handler)
{
    m_handler = handler;
}