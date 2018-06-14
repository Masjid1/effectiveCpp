/// �� T1 ת��Ϊ T2 ����: T1 -> T2
/// ���������⣺
/// 1. error: only declarations of constructors can be 'explicit'
/// explicit��������ֹ���캯��������ʽת���ģ�����explicit��ֻ�ܽ�����ʽת����

#include <iostream>

using namespace std;

class T2;

class T1
{
public:
    explicit T1(int _content) : content(_content) { }
    operator T2();   /// ��ʽת��,��ú���������non-explicit��
    const int& getContent() { return content; }
private:
    int content;
};

class T2
{
public:
    explicit T2(int _content) : content(_content) { }
    /// ��T1Ϊ��һ�����Ĺ��캯����
    /// ������������T2->T1����ʽ����ת������ú���������non-explicit��
    explicit T2(T1 t1) : content(t1.getContent()) { }
    const int& getContent() { return content; }
private:
    int content;
};

T1::operator T2()   /// ��ʽת��
{
    return T2(content); /// ʹ��T2�Ĺ��캯��
}

void func(T2 t2)
{
    cout << "the function only recieves 'T2' type.\nT2����������Ϊ: " << t2.getContent() << endl;
}

int main()
{
    T1 t1(100);
    T2 t2(t1);

//    func(static_cast<T2>(t1));  /// ��ʽת��
    func(t1);

    cout << "Hello world!" << endl;
    return 0;
}
