/// ��ʽת������

/// ��д������ʱ�����Ĵ���
///    1. �ඨ��������Ǽ�**�ֺ�**������"incomplete type"����
///    2. ����������main()ʱ��main()���õ��ĺ�������Ҫ���������õ��������Ҫ����������(class className{...}; �������������ĳ�Ա�����ͳ�Ա����)��
///    ���������ʱ�õ���һ����δ������࣬��ʱҪ�������������(class className;)�����ඨ����ɺ��ڶ���֮ǰ���������ֵ��ࡣ
///    3. error: only declarations of constructors can be 'explicit'
///    4. copying constructor function's parameter must be const reference type.

#include "Item15.h"

int main()
{
    Font font(getFont()); /// �����Դ
    cout << "case 1:\n" << string(50, '-') << endl;
    changeFontSize(font.get(), 18); /// ͨ��public��Ա�������FontHandle

    cout << "case 2:\n" << string(50, '-') << endl;
    changeFontSize(font, 16);       /// ͨ����ʽת�����FontHandle

    cout << "\n" << string(25, '=') << "end" << string(25, '=') << endl;
    return 0;
}
