#include <iostream>
#include <string>

using namespace std;

class FontHandle
{
public:
    explicit FontHandle(/*int _fontSize, string _name*/);

    /// error: invalid constructor; you probably meant 'FontHandle (const FontHandle&)'|
    /// Font类以FontHandle为参数的构造函数使用了列表初始化，所以FontHandle必须要有拷贝构造函数。
    /// 拷贝构造函数的参数是同类型的const reference。
    /// warning: 'FontHandle::fontSize' should be initialized in the member initialization list [-Weffc++]|
    /// 由此可见，警告是不能忽视的。
    /// 拷贝构造函数必须在成员初始化列表中初始化所有成员，编译器会警告不会报错。
    /// 成员变量未完全初始化可能导致隐藏的错误。
    FontHandle(const FontHandle& rhs);
/*public:
    int fontSize;
private:
    string name;*/
};

/// 以下三个函数必须声明再class FontHandle定义之后
FontHandle getFont();   ///获得资源
/// function releaseFont必须声明在class Font定义之前
void releaseFont(FontHandle);         ///释放资源
/// C API : pass by value, global function, whose first parameter is raw resource
void changeFontSize(FontHandle f, int newSize);


/// 由构造函数和析构函数可以看出，Font是一个RAII类(RAII: 资源获取时就初始化)
class Font {
public:
    explicit Font(FontHandle fh);    /// 获得资源，C API 采用 pass by value。
    ~Font();

    FontHandle get() const;        /// 显式转换函数，获得原始资源
    operator FontHandle() const;   /// 隐式转换函数，获得原始资源
private:
    FontHandle f;
};
