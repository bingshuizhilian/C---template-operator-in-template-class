#include "printer.h"
#include "types.h"

int main()
{
    cout << Printer<TYPE_A>(TYPE_A(9, 1.2, -5.3));
    cout << Printer<TYPE_B>(TYPE_B('k', "asd", "ijo"));

    return 0;
}
