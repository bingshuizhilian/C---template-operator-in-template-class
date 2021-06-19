#ifndef PRINTER_HPP
#define PRINTER_HPP

#include <iostream>
#include "types.h"

using namespace std;

/// forward declaration moved to types.h to avoid compiler warning
//template <typename T> class Printer;
//template <typename T>
//std::ostream &operator<<(std::ostream &os, const Printer<T> &rhs);

struct TYPE_A;
template <> std::ostream &operator<<(std::ostream &os, const Printer<TYPE_A> &object);
class TYPE_B;
template <> std::ostream &operator<<(std::ostream &os, const Printer<TYPE_B> &object);

template <typename T>
class Printer
{
public:
    Printer(const T& t)
        : m_t(t)
    {
    }

    friend std::ostream &operator<< <>(std::ostream &os, const Printer<T> &object);

    template<typename U = T>
    void fooA(typename std::enable_if_t<std::is_same_v<U, TYPE_A>>* pa)
    {
        const TYPE_A* p = reinterpret_cast<TYPE_A*>(pa);
        std::cout << p->ival << std::endl;
        std::cout << "TYPE_A matches param type, so function fooA is generated" << std::endl;
    }

    template<typename U = T>
    typename std::enable_if_t<std::is_same_v<U, TYPE_B>>
    fooB()
    {
        std::cout << "TYPE_B matches return type, so function fooB is generated" << std::endl;
    }

private:
    T m_t;
};

#endif // PRINTER_HPP
