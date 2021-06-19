#ifndef TYPES_H
#define TYPES_H

#include <vector>
#include <map>
#include <iostream>
#include <string>
#include "printer.h"

using namespace std;

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

#endif // TYPES_H


