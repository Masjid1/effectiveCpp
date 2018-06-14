#include <iostream>

using namespace std;

/// error: local variable 'i' may not appear in this context
/// 参数默认值不能使用函数自己的本地变量(局部变量)
int g = 100; /// global variant g.
void paraPass(int i=++g, int j=++g, int k=++g)
{
    cout << i << ' '
         << j << ' '
         << k << endl;
}

void paraPass2(int i=g+3, int j=g+2, int k=g+1)
{
    g += 3;
    cout << i << ' '
         << j << ' '
         << k << endl;
}

int _i = g+3;
int _j = g+2;
int _k = g+1;
void paraPass3(int i=_i, int j=_j, int k=_k)
{
    g += 3;
    cout << i << ' '
         << j << ' '
         << k << endl;
}

int main()
{
    paraPass();
    paraPass(1);
    paraPass(1,2);
    paraPass(1,2,3);
/*
output:
103 102 101
1 105 104
1 2 106
1 2 3
*/
/// 由输出可知：本编译器处理函数参数时，其顺序是从右到左的。
/// C#，java的参数核算是按照特定次序的。C++不同编译器，核算函数参数时，次序不一定相同。
/// 因此，函数参数可能不同。为避免这种不稳定性，函数参数的默认值应该尽量使用单个变量或常量，
/// 而非复杂的表达式,尤其是明显依赖执行顺序的表达式，如并列的多个自增操作。
/// 由于paraPass2的参数默认值的表达式十分简单，所以没有问题，如果不是简单的加上一个常数，这种写法也会有问题。
/// 最安全的写法是paraPass3这种，语句严格按照先后顺序执行。
    paraPass2(1);
    paraPass2(1,2);
    paraPass2(1,2,3);

    paraPass3(1);
    paraPass3(1,2);
    paraPass3(1,2,3);

    cout << "Hello world!" << endl;
    return 0;
}
