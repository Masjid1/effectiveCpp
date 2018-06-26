#include <iostream>
#include "main.h"

/**
    swap名字查找符合预期。
    警告：WidgetImpl及Widget的实现有些问题，当调用std::swap的非特化版本时，执行时间很长，约85s。
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
