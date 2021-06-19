#ifndef PRINTER_HPP
#define PRINTER_HPP

#include <iostream>

using namespace std;

template <typename T> class Printer;
template <typename T>
std::ostream &operator<<(std::ostream &os, const Printer<T> &rhs);

class TYPE_A;
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

private:
    T m_t;
};

#endif // PRINTER_HPP
