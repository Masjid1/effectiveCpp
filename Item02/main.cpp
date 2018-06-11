#include <iostream>
#include "main.h"

#define MAX(a, b) f((a)>(b)?(a):(b))

using std::cout;
using std::endl;

const int GamePlayer2::NumTurns = 5;
const double GamePlayer3::Pi = 3.141592654;

double f(double d)
{
    cout << "in f: "<< d << endl;
    return d;
}

int main()
{
    GamePlayer gp;
    int a = 5;
    double b = 5.3;
    int c = 10;
    cout << MAX(a,b) << endl;
    cout << "a: " << a << "\tb: " << b << endl;
    /// 此处是用++a替换宏实参a, 于是比较大小时a自增了一次，a>b时，a自增了一次。
    cout << MAX(++a,b) << endl;
    cout << "a: " << a << "\tb: " << b << endl;
    cout << MAX(++a,c) << endl;
    cout << "a: " << a << "\tb: " << b << endl;

    return 0;
}
