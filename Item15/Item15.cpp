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
Font::Font(FontHandle fh)    /// �����Դ��C API ���� pass by value��
     : f(fh)
{
    cout << "Font'ctor: Font(FontHandle fh)\n";
}

Font::~Font()
{
    cout << "Font'dtor: destructor.\n";
    releaseFont(f);
}

FontHandle Font::get() const { return f; }        /// ��ʽת�����������ԭʼ��Դ

/// ��ʽת��������ǩ��ʽ: "operator ����ֵ������()"
/// �޲������ͣ���ʽ����this, �˴�ΪFontָ��;
/// ����ͷ���޷���ֵ�����������з�����䣬����ֵ���;��Ǻ������֡�
Font::operator FontHandle() const { return f; }   /// ��ʽת�����������ԭʼ��Դ


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
