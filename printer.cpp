#include "printer.h"
#include "types.h"

template <>
std::ostream &operator<<(std::ostream &os, const Printer<TYPE_B> &object)
{
    os << object.m_t.aval << std::endl;
    os << object.m_t.cval << std::endl;
    os << object.m_t.svec.front() << std::endl;
    os << object.m_t.svec.back() << std::endl;

    return os;
}

template <>
std::ostream &operator<<(std::ostream &os, const Printer<TYPE_A> &object)
{
    os << object.m_t.ival << std::endl;
    os << object.m_t.dvec.front() << std::endl;
    os << object.m_t.dvec.back() << std::endl;

    return os;
}
