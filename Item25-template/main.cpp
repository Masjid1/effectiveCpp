#include <iostream>
#include "main.h"

/**
    ģ����ʽ��WidgetImpl��Widget��
    ����swap���ֲ��ҷ���Ԥ��.
    ����
        1. ���Ա����pImpl��һ��ָ�룬δ��ʼ����ʹ���ˡ�

    ���⣺
        1.new�����붨����������:
            һ�㶨������ʹ��: ���ù��캯���������, ʹ�ö��󣬶��󱣴���ջ�ռ��У����Զ�������
            new������Ҫʹ��ָ����գ�new�����Ķ��󱣴��ڶѿռ��У���Ҫdelete����.
*/

using std::cout;
using std::endl;

int main()
{
    win::Widget<int> a(2), b(3);
    using std::swap;
    swap(a, b);
    cout << "Hello world!" << endl;
    return 0;
}
