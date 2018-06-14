#include <iostream>

using namespace std;

int& refInt(int b) {
    return b;
}

int main()
{
    int a = 10;
    /// a, b1拷贝了a, b2拷贝了b1的引用，返回b2的引用。
    cout << refInt(refInt(a)) << endl;

    /// ra 引用 a, 并未创建 a 的备份
    int& ra = a;
    ra = 100;
    cout << "a=100:\ta=" << a << endl;

    /// b 创建了一份 ra 也是 a 的备份。
    int b = ra;
    b = 200;
    cout << "a==100:\ta=" << a << endl;
    cout << "ra==100:\tra=" << ra << endl;

    cout << "Hello world!" << endl;
    return 0;
}
