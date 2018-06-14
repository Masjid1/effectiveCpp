/// 对于内置类型、STL迭代器、函数对象, 采用Pass-by-value;
/// 对于其他对象, 尽量采用Pass-by-reference-to-const.
/// 派生类对象（non-pointer, non-reference）转换成基类对象时，存在对象切割(slicing)问题。

/// 遇到的错误：
/// 1. 定义派生类时，忘记写继承语句。（。。。）
/// 2. 只有指针、引用采用动态转型(dynamic_cast)。
/// 3. /// error: 'class Base' has no member named 'printDerived'
///    pb为基类指针，只能访问基类函数。因为print是虚函数，所以实际调用的是派生类的print函数。

#include <iostream>

using namespace std;

class Base
{
public:
    virtual void print()
    {
        cout << "this is virtual print function of base.\n";
    }
};

class Derived : public Base
{
public:
    virtual void print()
    {
        cout << "this is virtual print function of derived.\n";
    }
    void printDerived()
    {
        cout << "this is printDeriveed function of derived.\n";
    }
};

int main()
{
    Base b = Derived();
    b.print();
    /// this is virtual print function of base.

    Derived d;
    Base* pb = &d;
    pb->print();
    /// this is virtual print function of derived.

    /// error: 'class Base' has no member named 'printDerived'
    /// pb为基类指针，只能访问基类函数，因为print是虚函数，所以实际调用的是派生类的print函数。
    /// pb->printDerived();

    cout << "Hello world!" << endl;
    return 0;
}
