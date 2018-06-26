#include <iostream>
#include <string>
#include "myClass.h"

using std::cout;
using std::endl;
using std::string;



int main()
{
    /** 此处"空类"的定义:
    不含 non-static成员变量,
    不含 virtual函数(该类函数会为对象带来一个虚指针vptr),
    不含非空基类 的类.
    不含 virtual base class 的类. ? ??????????
    */

    cout << "sizeof(myClass)" << sizeof(myClass) << endl;   // 4
    /// C++ 规定凡是独立(非附属)对象都必须有非零大小,所以一个空类Empty对象所占内存在大多数编译器中为1.
    cout << "sizeof(Empty): " << sizeof(Empty) << endl;     // 1
    cout << "sizeof(HoldsAnChar): " << sizeof(HoldsAnChar) << endl;                 // 1
    cout << "sizeof(HoldsAnCharAndEmpty): " << sizeof(HoldsAnCharAndEmpty) << endl; // 2 = 1+1
    cout << "sizeof(HoldsAnInt): " << sizeof(HoldsAnInt) << endl;                   // 4
    /// 因为已经有了一个int类型的对象其大小为4,根据对齐alignment要求,Empty对象所占空间调整为4,总共为8.
    /// 对齐规则:如果占用内存最多的对象占用的内存小于8,则对齐到该最大占用内存;否则,对齐到8.
    cout << "sizeof(HoldsAnIntAndEmpty): " << sizeof(HoldsAnIntAndEmpty) << endl;   // 8 = 4+(1->4)
    cout << "sizeof(HoldsAnDouble): " << sizeof(HoldsAnDouble) << endl;                 // 8
    cout << "sizeof(HoldsAnDoubleAndEmpty): " << sizeof(HoldsAnDoubleAndEmpty) << endl; // 16 = 8+(1->8)
    cout << "sizeof(HoldsAnCharAndAnDouble): " << sizeof(HoldsAnCharAndAnDouble) << endl;                   // 16 = (1->8)+8
    cout << "sizeof(HoldsAnCharAndAnDoubleAndEmpty): " << sizeof(HoldsAnCharAndAnDoubleAndEmpty) << endl;   // 24 = (1->8)+8+(1->8)
    cout << "sizeof(com): " << sizeof(com) << endl;                 // 24 = (1->8)+8+(1->8)
    cout << "sizeof(comAndEmpty): " << sizeof(comAndEmpty) << endl; // 32 = (1->8)+8+(1->8) + (1->8)
    /// 基类为空不占内存,派生类为空占1byte.空类作为父类不占内存,空类作为成员变量占用内存不为零.
    cout << "sizeof(DerivedbyEmpty): " << sizeof(DerivedbyEmpty) << endl; // 1
    cout << "sizeof(DerivedbyEmptyHasAnInt): " << sizeof(DerivedbyEmptyHasAnInt) << endl; // 4
    cout << "sizeof(EmptyClass): " << sizeof(EmptyClass) << endl; // 4
    return 0;
}


void printMacro()
{
/**
__LINE__         当前语句所在的行号, 以10进制整数标注.

__FUNCTION__     当前语句所在的函数名

__FILE__         当前源文件的文件名, 以字符串常量标注.
__DATE__         程序被编译的日期, 以"Mmm dd yyyy"格式的字符串标注.
__TIME__         程序被编译的时间, 以"hh:mm:ss"格式的字符串标注, 该时间由asctime返回.

__STDC__         如果当前编译器符合ISO标准, 那么该宏的值为1
__STDC_VERSION__ 如果当前编译器符合C89, 那么它被定义为199409L, 如果符合C99, 那么被定义为199901L.

__STDC_HOSTED__  如果当前系统是"本地系统(hosted)", 那么它被定义为1. 本地系统表示当前系统拥有完整的标准C库.

__VERSION__      编译器版本:5.3.0

*/
    cout << "__STDC__: "            << __STDC__ << endl;
    cout << "__STDC_HOSTED__: "     << __STDC_HOSTED__ << endl;
    cout << "__VERSION__: "         << __VERSION__ << endl;
    cout << "__DATE__: "            << __DATE__ << endl;
    cout << "__TIME__: "            << __TIME__ << endl;
    cout << "__FILE__: "            << __FILE__ << endl;
    cout << "__FUNCTION__: "        << __FUNCTION__ << endl;
    cout << "__LINE__: "            << __LINE__ << endl;
}
