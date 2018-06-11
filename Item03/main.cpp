#include "myClass.h"

size_t newTB::length() const
{
    if(!lengthIsValid){
        /// 如果newTB::textLength是一般成员变量，则此赋值操作无法通过编译
        /// error: assignment of member 'newTB::textLength' in read-only object|
        /// 可在此变量声明处添加mutable,即表示此变量是可能变化的, 释放掉non-static成员变量的 bitwise constness 约束。
        /// 此时为 logical constness.
        textLength = strlen(pText);
        lengthIsValid = true;
    }
    return textLength;
}

int main()
{
    const CTextBlock ctb("CTextBlock");
    /// 调用常量成员函数
    cout << std::boolalpha << (ctb[1]=='T') << ' ' << ctb[1] << endl;

    CTextBlock tb("cout");
    /// 调用一般成员函数，下面一行的赋值操作虽然通过了编译，但执行时出错了。
//    tb[1] = 'i';
    cout << (tb[1]=='o') << ' ' << (tb[1]=='i') << ' ' << tb.value() << endl;

    /// &ctb[1] 是'const char* '类型的。
    const char* pc1 = &ctb[1];
    cout << (ctb[1]=='T') << ' ' << (ctb[1]=='i') << ' ' << *pc1 << ' ' << ctb.value() << endl;

    /// &tb[1] 是'char* '类型的，但不能对其赋值，下面一行的赋值操作可通过编译，但不能正确执行。
    char* pc2 = &tb[1];
//    *pc2 = 'i';
    cout << (tb[1]=='o') << ' ' << (tb[1]=='i') << ' ' << *pc2 << ' ' << tb.value() << endl;

    cout << "Hello world!" << endl;
    return 0;
}
