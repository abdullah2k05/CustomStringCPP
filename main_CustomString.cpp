// main.cpp
// Library by MUHAMMAD ABDULLAH ( @abdullah2k05 )
// https://github.com/abdullah2k05/
#include "CustomString.h"

int main()
{
    CustomString t1;
    t1 = "Hello world";
    cout << t1 << endl;

    CustomString t2;
    t2 = "This is a test ";
    cout << t2 << endl;

    CustomString t3 = t1 + t2;
    cout << t3 << endl;

    cin >> t3;
    cout << endl << "Final with input = " << t3;
}
