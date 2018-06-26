/**
    验证: derived class 可重新定义继承的private virtual function.
    基类的private修饰符限制了派生类对该函数的使用, 但派生类仍可以重新定义该函数做什么.
*/

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


class Base{
public:
    /// warning: 'class Base' has virtual functions and accessible non-virtual destructor [-Wnon-virtual-dtor]|
    virtual ~Base() {}
    /// NVI手法,提供非虚接口,调用虚函数实现. 因为基类和派生类的该函数实现完全相同,所以他不用是虚函数.
    void printCall() { print(); }
private:
    virtual void print(){ cout << "this is Base::print.\n"; }
};

class Derived : public Base{
public:
    virtual ~Derived() { }

/// 注意: 因为Base::print是private的, 所以Derived在类内,Derived的派生类内,类外均不能调用它.
/// 该函数的修饰符是什么是无意义的,一般使用权限最低的private, 以免在Derived的派生类内,类外误用.
private:
    void print(){ cout << "this is Derived::print.\n"; }
};

int main()
{
    Base b;
    Derived d;
    Base* pb = &d;
    b.printCall();  // Base::print
    d.printCall();  // Derived::print
    pb->printCall();// Derived::print

    return 0;
}
