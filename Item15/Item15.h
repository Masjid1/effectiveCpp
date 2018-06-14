#include <iostream>
#include <string>

using namespace std;

class FontHandle
{
public:
    explicit FontHandle(/*int _fontSize, string _name*/);

    /// error: invalid constructor; you probably meant 'FontHandle (const FontHandle&)'|
    /// Font����FontHandleΪ�����Ĺ��캯��ʹ�����б��ʼ��������FontHandle����Ҫ�п������캯����
    /// �������캯���Ĳ�����ͬ���͵�const reference��
    /// warning: 'FontHandle::fontSize' should be initialized in the member initialization list [-Weffc++]|
    /// �ɴ˿ɼ��������ǲ��ܺ��ӵġ�
    /// �������캯�������ڳ�Ա��ʼ���б��г�ʼ�����г�Ա���������ᾯ�治�ᱨ��
    /// ��Ա����δ��ȫ��ʼ�����ܵ������صĴ���
    FontHandle(const FontHandle& rhs);
/*public:
    int fontSize;
private:
    string name;*/
};

/// ����������������������class FontHandle����֮��
FontHandle getFont();   ///�����Դ
/// function releaseFont����������class Font����֮ǰ
void releaseFont(FontHandle);         ///�ͷ���Դ
/// C API : pass by value, global function, whose first parameter is raw resource
void changeFontSize(FontHandle f, int newSize);


/// �ɹ��캯���������������Կ�����Font��һ��RAII��(RAII: ��Դ��ȡʱ�ͳ�ʼ��)
class Font {
public:
    explicit Font(FontHandle fh);    /// �����Դ��C API ���� pass by value��
    ~Font();

    FontHandle get() const;        /// ��ʽת�����������ԭʼ��Դ
    operator FontHandle() const;   /// ��ʽת�����������ԭʼ��Դ
private:
    FontHandle f;
};
