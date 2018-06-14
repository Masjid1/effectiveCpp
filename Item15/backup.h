
/// ��ʽת������

/// ��д������ʱ�����Ĵ���
///     �ඨ��������Ǽ�**�ֺ�**������"incomplete type"����

#include <iostream>
#include <string>

using namespace std;

/// ע���ࡢ����������˳���ʵ��˳��

class FontHandle
{
public:
    explicit FontHandle(int _fontSize, string _name)
    : fontSize(_fontSize),
      name(_name) {
        cout << "FontHandle's ctor.\n";
    }
    /// error: invalid constructor; you probably meant 'FontHandle (const FontHandle&)'|
    /// Font����FontHandleΪ�����Ĺ��캯��ʹ�����б��ʼ��������FontHandle����Ҫ�п������캯����
    /// �������캯���Ĳ�����ͬ���͵�const reference��
    /// warning: 'FontHandle::fontSize' should be initialized in the member initialization list [-Weffc++]|
    /// �ɴ˿ɼ��������ǲ��ܺ��ӵġ�
    /// �������캯�������ڳ�Ա��ʼ���б��г�ʼ�����г�Ա���������ᾯ�治�ᱨ��
    /// ��Ա����δ��ȫ��ʼ�����ܵ������صĴ���
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

/// �ɹ��캯���������������Կ�����Font��һ��RAII��(RAII: ��Դ��ȡʱ�ͳ�ʼ��)
class Font {
public:
    explicit Font(FontHandle fh)    /// �����Դ��C API ���� pass by value��
     : f(fh)
    {
        cout << "Font'ctor: Font(FontHandle fh)\n";
    }
    ~Font() {
        cout << "Font'dtor: destructor.\n";
        releaseFont(f);
    }

    FontHandle get() const { return f; }        /// ��ʽת�����������ԭʼ��Դ
    operator FontHandle() const { return f; }   /// ��ʽת�����������ԭʼ��Դ
private:
    FontHandle f;
};

int main()
{
    Font font(getFont()); /// �����Դ
    cout << "case 1:\n" << string(50, '-') << endl;
    changeFontSize(font.get(), 18); /// ͨ��public��Ա�������FontHandle

    cout << "case 2:\n" << string(50, '-') << endl;
    changeFontSize(font, 16);       /// ͨ����ʽת�����FontHandle

    cout << string(25, '-') << "end" << string(25, '-') << endl;
    return 0;
}
