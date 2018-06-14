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
    /// ����effective c++���飬Ӧ�ø�Ϊreturn by value.

    /// ��Ϊ��Ԫ��������������������������Ϊprivate�ġ�
    friend Rational& operator* (const Rational& lhs, const Rational& rhs)
    {
        static Rational result(lhs.n * rhs.n, lhs.d * rhs.d);
        return result;
    }

};

int main()
{
    /// ��������sfs����һ�����뵥Ԫ�ж��壨��һ�У���
    /// ��������(�ڶ���)����δ����ġ�
    static FileSystem sfs;
    cout << sfs.numDisks() << endl;
    /// ����һ��ͨ���������ã�ȷ������Ķ����ʹ�ã������䣩��ͬһ�����뵥Ԫ���������δ������Ϊ��
    cout << tfs().numDisks() << endl;

    Rational a(3,7), b(7,3), c(42, 89), d;

    int ii =34;
    double dd = 4.2;

    d = a*b*c;
    pair<int, int> result = d.valueFraction();
    cout << result.first << '/' << result.second << endl;
    cout << d.valueDecimal() << endl;

    cout << boolalpha << ((a*b)==(a*c)) << noboolalpha << endl;

    cout << "Hello world!" << endl;
    return 0;
}
