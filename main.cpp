#include "printer.h"

int main()
{
    cout << Printer<TYPE_A>(TYPE_A(9, 1.2, -5.3));
    cout << Printer<TYPE_B>(TYPE_B('k', "asd", "ijo"));

    TYPE_A a(158, 156.9848, -5894.165);
    Printer<TYPE_A> pa(a);
    pa.fooA(&a);
//    pa.fooB(); //got an compile time error
    cout << pa;

    TYPE_B b('=', "345hg", "1.65gha");
    Printer<TYPE_B> pb(b);
 //    pb.fooA(); //got an compile time error
    pb.fooB();
    pb.fooB2();
    cout << pb;

    return 0;
}
