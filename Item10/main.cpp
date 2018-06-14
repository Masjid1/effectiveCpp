#include <iostream>

using namespace std;

class Widget {
public:
    Widget(int w=0, int h=0)
    : width(w),
      height(h) { }

    /// error: only constructors take member initializers
///    Widget operator=(const Widget rhs)
///    : width(rhs.width),
///      height(rhs.height) { }

    Widget operator=(const Widget rhs) {
        width = rhs.width;
        height = rhs.height;
        return *this;
    }

    void showSize() {
        cout << "width: " << width << "\theight: " << height << endl;
    }
private:
    int width;
    int height;
};

int main()
{
    Widget w1(600, 480), w2, w3, w4;
    w4 = w3 = w2 = w1;
    w1.showSize();
    w2.showSize();
    w3.showSize();
    w4.showSize();

    cout << "Hello world!" << endl;
    return 0;
}
