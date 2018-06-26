/**
    ��֤: derived class �����¶���̳е�private virtual function.
    �����private���η�������������Ըú�����ʹ��, ���������Կ������¶���ú�����ʲô.
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
    /// NVI�ַ�,�ṩ����ӿ�,�����麯��ʵ��. ��Ϊ�����������ĸú���ʵ����ȫ��ͬ,�������������麯��.
    void printCall() { print(); }
private:
    virtual void print(){ cout << "this is Base::print.\n"; }
};

class Derived : public Base{
public:
    virtual ~Derived() { }

/// ע��: ��ΪBase::print��private��, ����Derived������,Derived����������,��������ܵ�����.
/// �ú��������η���ʲô���������,һ��ʹ��Ȩ����͵�private, ������Derived����������,��������.
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
