/// 隐式转换函数

/// 编写本程序时所犯的错误：
///    1. 类定义语句忘记加**分号**，导致"incomplete type"错误。
///    2. 编译器遇到main()时，main()中用到的函数必须要有声明，用到的类必须要有完整声明(class className{...}; 类的声明包含类的成员变量和成员函数)。
///    如果定义类时用到了一个还未定义的类，此时要先声明类的名字(class className;)，该类定义完成后，在定义之前声明类名字的类。
///    3. error: only declarations of constructors can be 'explicit'
///    4. copying constructor function's parameter must be const reference type.

#include "Item15.h"

int main()
{
    Font font(getFont()); /// 获得资源
    cout << "case 1:\n" << string(50, '-') << endl;
    changeFontSize(font.get(), 18); /// 通过public成员函数获得FontHandle

    cout << "case 2:\n" << string(50, '-') << endl;
    changeFontSize(font, 16);       /// 通过隐式转换获得FontHandle

    cout << "\n" << string(25, '=') << "end" << string(25, '=') << endl;
    return 0;
}
