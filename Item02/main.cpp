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
    /// �˴�����++a�滻��ʵ��a, ���ǱȽϴ�Сʱa������һ�Σ�a>bʱ��a������һ�Ρ�
    cout << MAX(++a,b) << endl;
    cout << "a: " << a << "\tb: " << b << endl;
    cout << MAX(++a,c) << endl;
    cout << "a: " << a << "\tb: " << b << endl;

    return 0;
}
