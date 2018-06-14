#include <iostream>

using namespace std;

/// error: local variable 'i' may not appear in this context
/// ����Ĭ��ֵ����ʹ�ú����Լ��ı��ر���(�ֲ�����)
int g = 100; /// global variant g.
void paraPass(int i=++g, int j=++g, int k=++g)
{
    cout << i << ' '
         << j << ' '
         << k << endl;
}

void paraPass2(int i=g+3, int j=g+2, int k=g+1)
{
    g += 3;
    cout << i << ' '
         << j << ' '
         << k << endl;
}

int _i = g+3;
int _j = g+2;
int _k = g+1;
void paraPass3(int i=_i, int j=_j, int k=_k)
{
    g += 3;
    cout << i << ' '
         << j << ' '
         << k << endl;
}

int main()
{
    paraPass();
    paraPass(1);
    paraPass(1,2);
    paraPass(1,2,3);
/*
output:
103 102 101
1 105 104
1 2 106
1 2 3
*/
/// �������֪��������������������ʱ����˳���Ǵ��ҵ���ġ�
/// C#��java�Ĳ��������ǰ����ض�����ġ�C++��ͬ�����������㺯������ʱ������һ����ͬ��
/// ��ˣ������������ܲ�ͬ��Ϊ�������ֲ��ȶ��ԣ�����������Ĭ��ֵӦ�þ���ʹ�õ�������������
/// ���Ǹ��ӵı��ʽ,��������������ִ��˳��ı��ʽ���粢�еĶ������������
/// ����paraPass2�Ĳ���Ĭ��ֵ�ı��ʽʮ�ּ򵥣�����û�����⣬������Ǽ򵥵ļ���һ������������д��Ҳ�������⡣
/// �ȫ��д����paraPass3���֣�����ϸ����Ⱥ�˳��ִ�С�
    paraPass2(1);
    paraPass2(1,2);
    paraPass2(1,2,3);

    paraPass3(1);
    paraPass3(1,2);
    paraPass3(1,2,3);

    cout << "Hello world!" << endl;
    return 0;
}
