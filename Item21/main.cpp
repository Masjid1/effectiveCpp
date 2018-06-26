// usage of static object.

#include <iostream>

using namespace std;

class FileSystem
{
public:
    int numDisks() { return 100; }
};

/// return the reference to static object.
FileSystem& tfs()
{
    static FileSystem fs;
    return fs;
}

class Rational
{
public:
    Rational(int numerator = 0, int denominator = 1)
     : n(numerator), d(denominator) { }
    pair<int,int> valueFraction()
    {
        return make_pair(n,d);
    }
    double valueDecimal()
    {
        return static_cast<double>(n)/d;
    }
    bool operator== (const Rational& rhs) const
    {
        if(n == rhs.n && d == rhs.d)
            return true;
        else
            return false;
    }
private:
    int n, d;
    /// warning: 'Rational& operator*(const Rational&, const Rational&)' should return by value [-Weffc++]
    /// 根据effective c++建议，应该改为return by value.

    /// 此为友元函数，所以有两个参数，可以为private的。
    friend Rational& operator* (const Rational& lhs, const Rational& rhs)
    {
        /// static 对象只初始化（或赋值）一次，所以result永远为(n=21, d=21)。
        static Rational result(lhs.n * rhs.n, lhs.d * rhs.d);
        return result;
    }

};

int main()
{
    /// 如果下面的sfs在另一个编译单元中定义（第一行），
    /// 则输出语句(第二行)将是未定义的。
    static FileSystem sfs;
    cout << sfs.numDisks() << endl;
    /// 下面一行通过函数调用，确保对象的定义和使用（输出语句）在同一个编译单元，不会出现未定义行为。
    cout << tfs().numDisks() << endl;

    Rational a(3,7), b(7,3), c(42, 89), d;

    int ii =34;
    double dd = 4.2;
    /// 因为*运算返回的是对静态对象的引用，之后的所有的*运算中静态对象不再变化，所以返回值引用的对象不变，恒为(n=21, d=21)。
    d = a*b*c*a*b;

    pair<int, int> n_m = d.valueFraction();
    cout << n_m.first << '/' << n_m.second << endl;
    cout << d.valueDecimal() << endl;

    /// 等号两边都是对operator*()函数内静态对象的引用
    cout << boolalpha << ((b*b)==(a*c)) << noboolalpha << endl;

    cout << (b*b).valueDecimal() << endl;

    cout << "Hello world!" << endl;
    return 0;
}
