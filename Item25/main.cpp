#include <iostream>
#include "main.h"

/**
    swap���ֲ��ҷ���Ԥ�ڡ�
    ���棺WidgetImpl��Widget��ʵ����Щ���⣬������std::swap�ķ��ػ��汾ʱ��ִ��ʱ��ܳ���Լ85s��
*/

using std::cout;
using std::endl;

int main()
{
    win::Widget a, b;
    using std::swap;
    swap(a, b);
    cout << "Hello world!" << endl;
    return 0;
}
