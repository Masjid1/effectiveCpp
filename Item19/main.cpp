/// 将 T1 转换为 T2 类型: T1 -> T2
/// 遇到的问题：
/// 1. error: only declarations of constructors can be 'explicit'
/// explicit是用来禁止构造函数用于隐式转换的，带有explicit后只能进行显式转换。

#include <iostream>

using namespace std;

class T2;

class T1
{
public:
    explicit T1(int _content) : content(_content) { }
    operator T2();   /// 隐式转换,则该函数必须是non-explicit。
    const int& getContent() { return content; }
private:
    int content;
};

class T2
{
public:
    explicit T2(int _content) : content(_content) { }
    /// 以T1为单一参数的构造函数，
    /// 如果利用它完成T2->T1的隐式类型转换，则该函数必须是non-explicit。
    explicit T2(T1 t1) : content(t1.getContent()) { }
    const int& getContent() { return content; }
private:
    int content;
};

T1::operator T2()   /// 隐式转换
{
    return T2(content); /// 使用T2的构造函数
}

void func(T2 t2)
{
    cout << "the function only recieves 'T2' type.\nT2类对象的内容为: " << t2.getContent() << endl;
}

int main()
{
    T1 t1(100);
    T2 t2(t1);

//    func(static_cast<T2>(t1));  /// 显式转换
    func(t1);

    cout << "Hello world!" << endl;
    return 0;
}
