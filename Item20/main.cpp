/// �����������͡�STL����������������, ����Pass-by-value;
/// ������������, ��������Pass-by-reference-to-const.
/// ���������non-pointer, non-reference��ת���ɻ������ʱ�����ڶ����и�(slicing)���⡣

/// �����Ĵ���
/// 1. ����������ʱ������д�̳���䡣����������
/// 2. ֻ��ָ�롢���ò��ö�̬ת��(dynamic_cast)��
/// 3. /// error: 'class Base' has no member named 'printDerived'
///    pbΪ����ָ�룬ֻ�ܷ��ʻ��ຯ������Ϊprint���麯��������ʵ�ʵ��õ����������print������

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
    /// pbΪ����ָ�룬ֻ�ܷ��ʻ��ຯ������Ϊprint���麯��������ʵ�ʵ��õ����������print������
    /// pb->printDerived();

    cout << "Hello world!" << endl;
    return 0;
}
