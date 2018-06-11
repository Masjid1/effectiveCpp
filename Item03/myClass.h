#ifndef MYCLASS_H_INCLUDED
#define MYCLASS_H_INCLUDED

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::size_t;


class CTextBlock {
public:
    CTextBlock(char* text) : pText(text) { }

    /// const member function, 意味着该函数没有赋值操作，
    /// return value is const char&, 返回值是对text[position]的常量引用，可用来获得其值与地址，但不能直接对其赋值。
    const char& operator[](size_t position) const
    {
        cout << value() << endl;
        return pText[position];
    }

    /// 一般成员函数
    char& operator[](size_t position)
    {
        cout << value() << endl;
        return pText[position];
    }
    char* value() const { return pText; }
private:
    char* pText;
};

class newTB {
public:
    newTB(char* text) : pText(text) { }

    /// const member function, 意味着该函数没有赋值操作，
    /// return value is const char&, 返回值是对text[position]的常量引用，可用来获得其值与地址，但不能直接对其赋值。
    const char& operator[](size_t position) const
    {
        cout << value() << endl;
        return pText[position];
    }

    /// 一般成员函数
    char& operator[](size_t position)
    {
        cout << value() << endl;
        return pText[position];
    }
    char* value() const { return pText; }
    size_t length() const;
private:
    char* pText;
    mutable size_t textLength;
    mutable bool lengthIsValid;
};


#endif // MYCLASS_H_INCLUDED
