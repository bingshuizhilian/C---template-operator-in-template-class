#ifndef PRINTER_H
#define PRINTER_H

#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <type_traits>

using namespace std;

template <typename T> class Printer;
template <typename T>
std::ostream &operator<<(std::ostream &os, const Printer<T> &rhs);

struct TYPE_A
{
    int ival;
    std::vector<double> dvec;

    TYPE_A()
    {
        ival = 12;
        dvec.push_back(15.36);
        dvec.push_back(21.7);
    }

    TYPE_A(int i, double d1, double d2)
    {
        ival = i;
        dvec.push_back(d1);
        dvec.push_back(d2);
    }

    friend std::ostream &operator<<(std::ostream &os, const TYPE_A &a)
    {
        os << a.ival << std::endl;

        for(auto i: a.dvec)
        os << i << std::endl;

        return os;
    }
};

class TYPE_B
{
    char cval;
    std::vector<std::string> svec;
    TYPE_A aval;

public:
    TYPE_B()
    {
        cval = 'S';
        svec.push_back("lalala");
        svec.push_back("what is this");
    }

    TYPE_B(char c, std::string s1, std::string s2)
    {
        cval = c;
        svec.push_back(s1);
        svec.push_back(s2);
    }

    friend std::ostream &operator<< <>(std::ostream &os, const Printer<TYPE_B> &object);
};

template <>
std::ostream &operator<<(std::ostream &os, const Printer<TYPE_B> &object);
template <>
std::ostream &operator<<(std::ostream &os, const Printer<TYPE_A> &object);

template <typename T>
class Printer
{
public:
    Printer(const T& t)
        : m_t(t)
    {
    }

    friend std::ostream &operator<< <>(std::ostream &os, const Printer &object);
    /// same as below
//    friend std::ostream &operator<< <T>(std::ostream &os, const Printer<T> &object);

    template <typename U = T>
    void fooA(typename std::enable_if_t<std::is_same_v<U, TYPE_A>>* pa)
    {
        const TYPE_A* p = reinterpret_cast<TYPE_A*>(pa);
        std::cout << p->ival << std::endl;
        std::cout << "TYPE_A matches param type, so function fooA is generated" << std::endl;
    }


    template <typename U = T>
    typename std::enable_if_t<std::is_same_v<U, TYPE_B>>
    fooB()
    {
        std::cout << "TYPE_B matches return type, so function fooB is generated" << std::endl;
    }

    template <typename U = T,
    typename = typename std::enable_if_t<std::is_same_v<U, TYPE_B>>>
    void fooB2()
    {
        std::cout << "TYPE_B matches template parameter, so function fooB2 is generated" << std::endl;
    }

private:
    T m_t;
};

#endif // PRINTER_H
