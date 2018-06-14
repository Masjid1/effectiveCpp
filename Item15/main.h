
#include <iostream>
#include <string>

using namespace std;

/// 类、函数声明，main函数，类、函数的实现。
/// 注意类、函数的声明顺序和实现顺序。
//
//class FontHandle;
//FontHandle getFont();   ///获得资源
//void releaseFont(FontHandle);         ///释放资源
///// C API : pass by value, global function, whose first parameter is raw resource
//void changeFontSize(FontHandle f, int newSize);
//class Font;

class FontHandle
{
public:
    explicit FontHandle(int _fontSize, string _name)
    : fontSize(_fontSize),
      name(_name) {
        cout << "FontHandle's ctor.\n";
    }
    /// error: invalid constructor; you probably meant 'FontHandle (const FontHandle&)'|
    /// Font类以FontHandle为参数的构造函数使用了列表初始化，所以FontHandle必须要有拷贝构造函数。
    /// 拷贝构造函数的参数是同类型的const reference。
    /// warning: 'FontHandle::fontSize' should be initialized in the member initialization list [-Weffc++]|
    /// 由此可见，警告是不能忽视的。
    /// 拷贝构造函数必须在成员初始化列表中初始化所有成员，编译器会警告不会报错。
    /// 成员变量未完全初始化可能导致隐藏的错误。
    FontHandle(const FontHandle& rhs)
    : fontSize(rhs.fontSize),
      name(rhs.name)
    {
        cout << "FontHandle's copying constructor function.\tname: "
        << name << "\tfontSize: " << fontSize << endl;
    }
public:
    int fontSize;
private:
    string name;
};

FontHandle getFont()
{
    cout << "in getFont()\n";
    FontHandle fh(8, string("getFont"));
    return fh;
}

void releaseFont(FontHandle f)
{
    cout << "releaseFont\n";
}

void changeFontSize(FontHandle f, int newSize)
{
    f.fontSize = newSize;
    cout << "changeFontSize, new fontSize is " << f.fontSize << endl;
}

/// 由构造函数和析构函数可以看出，Font是一个RAII类(RAII: 资源获取时就初始化)
class Font {
public:
    explicit Font(FontHandle fh)    /// 获得资源，C API 采用 pass by value。
     : f(fh)
    {
        cout << "Font'ctor: Font(FontHandle fh)\n";
    }
    ~Font() {
        cout << "Font'dtor: destructor.\n";
        releaseFont(f);
    }

    FontHandle get() const { return f; }        /// 显式转换函数，获得原始资源
    operator FontHandle() const { return f; }   /// 隐式转换函数，获得原始资源
private:
    FontHandle f;
};



