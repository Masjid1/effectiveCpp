#include "myClass.h"

size_t newTB::length() const
{
    if(!lengthIsValid){
        /// ���newTB::textLength��һ���Ա��������˸�ֵ�����޷�ͨ������
        /// error: assignment of member 'newTB::textLength' in read-only object|
        /// ���ڴ˱������������mutable,����ʾ�˱����ǿ��ܱ仯��, �ͷŵ�non-static��Ա������ bitwise constness Լ����
        /// ��ʱΪ logical constness.
        textLength = strlen(pText);
        lengthIsValid = true;
    }
    return textLength;
}

int main()
{
    const CTextBlock ctb("CTextBlock");
    /// ���ó�����Ա����
    cout << std::boolalpha << (ctb[1]=='T') << ' ' << ctb[1] << endl;

    CTextBlock tb("cout");
    /// ����һ���Ա����������һ�еĸ�ֵ������Ȼͨ���˱��룬��ִ��ʱ�����ˡ�
//    tb[1] = 'i';
    cout << (tb[1]=='o') << ' ' << (tb[1]=='i') << ' ' << tb.value() << endl;

    /// &ctb[1] ��'const char* '���͵ġ�
    const char* pc1 = &ctb[1];
    cout << (ctb[1]=='T') << ' ' << (ctb[1]=='i') << ' ' << *pc1 << ' ' << ctb.value() << endl;

    /// &tb[1] ��'char* '���͵ģ������ܶ��丳ֵ������һ�еĸ�ֵ������ͨ�����룬��������ȷִ�С�
    char* pc2 = &tb[1];
//    *pc2 = 'i';
    cout << (tb[1]=='o') << ' ' << (tb[1]=='i') << ' ' << *pc2 << ' ' << tb.value() << endl;

    cout << "Hello world!" << endl;
    return 0;
}
