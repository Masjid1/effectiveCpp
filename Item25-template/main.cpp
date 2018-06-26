#include <iostream>
#include "main.h"

/**
    模板形式的WidgetImpl和Widget。
    函数swap名字查找符合预期.
    错误：
        1. 类成员变量pImpl是一个指针，未初始化就使用了。

    问题：
        1.new对象与定义对象的区别:
            一般定义对象的使用: 调用构造函数定义对象, 使用对象，对象保存在栈空间中，会自动析构。
            new对象需要使用指针接收，new创建的对象保存在堆空间中，需要delete销毁.
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
