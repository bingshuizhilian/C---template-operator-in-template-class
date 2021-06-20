#include "printer.h"
#include <algorithm>
#include <iterator>

template <>
std::ostream &operator<<(std::ostream &os, const Printer<TYPE_B> &object)
{
    os << "call operator<< of TYPE_B start" << std::endl;
    os << object.m_t.aval << std::endl;
    os << object.m_t.cval << std::endl;
    /// methord 1
    os << "methord 1 start" << std::endl;
    os << object.m_t.svec.front() << std::endl;
    os << object.m_t.svec.back() << std::endl;
    os << "methord 1 end" << std::endl;
    /// methord 2
    os << "methord 2 start" << std::endl;
    copy(object.m_t.svec.begin(), object.m_t.svec.end(),
         ostream_iterator<string>(os, "+++"));
    os << "methord 2 end" << std::endl;
    /// methord 3
    os << "methord 3 start" << std::endl;
    for_each(begin(object.m_t.svec), end(object.m_t.svec),
             [&](string s){ os << s << endl; });
    os << "methord 3 end" << std::endl;
    os << "call operator<< of TYPE_B end" << std::endl;

    return os;
}

template <>
std::ostream &operator<<(std::ostream &os, const Printer<TYPE_A> &object)
{
    os << "call operator<< of TYPE_A start" << std::endl;
    os << object.m_t.ival << std::endl;
    os << object.m_t.dvec.front() << std::endl;
    os << object.m_t.dvec.back() << std::endl;
    os << "call operator<< of TYPE_A end" << std::endl;

    return os;
}

/// defination out of class cause compile problems
//template <typename T>
//template <typename U>
//void Printer<T>::fooA(std::enable_if_t<std::is_same_v<U, TYPE_A> > *pa)
//{
//    const TYPE_A* p = reinterpret_cast<TYPE_A*>(pa);
//    std::cout << p->ival << std::endl;
//    std::cout << "TYPE_A matches param type, so function fooA is generated" << std::endl;
//}

//template <typename T>
//template <typename U>
//typename std::enable_if_t<std::is_same_v<U, TYPE_B>>
//Printer<T>::fooB()
//{
//    std::cout << "TYPE_B matches return type, so function fooB is generated" << std::endl;
//}
