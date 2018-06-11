// Effective C++ Page 5.
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class A
{
    friend void print(A a);
public:
    A() : i(0),d(0.0) { std::cout << "this is a default constructor.\n"; }
    A(int _i) : i(_i),d(0.0) {cout << "this ia not a default constructor which has a int type parameter.\n" << i << endl; }
    explicit A(double _d) : i(0),d(_d) {cout << "this ia not a default constructor which has a double type parameter.\n" << d << endl; }

    /// error: invalid constructor; you probably meant 'A (const A&)'|
    /// A(A rhs) : i(rhs.i),d(rhs.d) { cout << "this is a copy constructor.\n"; }
    A(const A& rhs) : i(rhs.i),d(rhs.d) { cout << "this is a copy constructor.\n"; }

    /// error: only constructors take member initializers|
    /// A& operator=(const A& rhs) : i(rhs.i),d(rhs.d) { cout << "this is a assignment operator.\n"; return *this; }
    A& operator=(const A& rhs){  i = rhs.i; d = rhs.d; cout << "this is a assignment operator.\n"; return *this; }
private:
    int i;
    double d;
};

class B
{
public:
    B(int x=0, string s="") { cout << "this is a default constructor function which has two default parameters.\n"; }
};

void print(A a)
{
    cout << "print A.\t" << a.i << "\t" << a.d << endl;
}

int main()
{
    A a1, a2(2), a3(3.14);
    print(a1);
    print(a2);
    print(a3);

    /// 以下三个print函数均会调用A(int i)，double型的2.73会转换成int型的2，char型的'a'会转换成97。
    /// 因为explicit A(double d)声明此构造函数是显式的，所以它不会被用来做double到A的隐式类型转换, 可使用A(2.73)生成一个临时A类型的变量，或视作显式类型转换。
    print(0);
    print(2.73);
    print(A(2.73));
    char c = 'a';
    print(c);

    A a4(a3);   // use copy constructor
    A a5 = a3;  // use copy constructor
    A a6;       // use default constructor
    a6 = a3;    // use assignment operator =

    return 0;
}
