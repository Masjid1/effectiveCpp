#include <iostream>

using namespace std;

int& refInt(int b) {
    return b;
}

int main()
{
    int a = 10;
    /// a, b1������a, b2������b1�����ã�����b2�����á�
    cout << refInt(refInt(a)) << endl;

    /// ra ���� a, ��δ���� a �ı���
    int& ra = a;
    ra = 100;
    cout << "a=100:\ta=" << a << endl;

    /// b ������һ�� ra Ҳ�� a �ı��ݡ�
    int b = ra;
    b = 200;
    cout << "a==100:\ta=" << a << endl;
    cout << "ra==100:\tra=" << ra << endl;

    cout << "Hello world!" << endl;
    return 0;
}
