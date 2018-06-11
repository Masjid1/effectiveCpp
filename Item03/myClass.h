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

    /// const member function, ��ζ�Ÿú���û�и�ֵ������
    /// return value is const char&, ����ֵ�Ƕ�text[position]�ĳ������ã������������ֵ���ַ��������ֱ�Ӷ��丳ֵ��
    const char& operator[](size_t position) const
    {
        cout << value() << endl;
        return pText[position];
    }

    /// һ���Ա����
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

    /// const member function, ��ζ�Ÿú���û�и�ֵ������
    /// return value is const char&, ����ֵ�Ƕ�text[position]�ĳ������ã������������ֵ���ַ��������ֱ�Ӷ��丳ֵ��
    const char& operator[](size_t position) const
    {
        cout << value() << endl;
        return pText[position];
    }

    /// һ���Ա����
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
