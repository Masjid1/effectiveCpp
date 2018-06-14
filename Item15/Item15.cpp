#include "Item15.h"

/// FontHandle
FontHandle::FontHandle(/*int _fontSize, string _name*/)
/*    : fontSize(_fontSize),
      name(_name)*/
{
    cout << "FontHandle's ctor.\n";
}

FontHandle::FontHandle(const FontHandle& rhs)
/*    : fontSize(rhs.fontSize),
      name(rhs.name)*/
{
    cout << "FontHandle's copying constructor function.\t"
         /*<< "name: " << name << "\tfontSize: " << fontSize */<< endl;
}


/// Font
Font::Font(FontHandle fh)    /// 获得资源，C API 采用 pass by value。
     : f(fh)
{
    cout << "Font'ctor: Font(FontHandle fh)\n";
}

Font::~Font()
{
    cout << "Font'dtor: destructor.\n";
    releaseFont(f);
}

FontHandle Font::get() const { return f; }        /// 显式转换函数，获得原始资源

/// 隐式转换函数的签名式: "operator 返回值类型名()"
/// 无参数类型，隐式传递this, 此处为Font指针;
/// 函数头部无返回值，函数体内有返回语句，返回值类型就是函数名字。
Font::operator FontHandle() const { return f; }   /// 隐式转换函数，获得原始资源


FontHandle getFont()
{
    cout << "in getFont()\n";
    FontHandle fh/*(8, string("getFont"))*/;
    return fh;
}

void releaseFont(FontHandle f)
{
    cout << "releaseFont\n";
}

void changeFontSize(FontHandle f, int newSize)
{
//    f.fontSize = newSize;
    cout << "changeFontSize, new fontSize is " << newSize << endl;
}
