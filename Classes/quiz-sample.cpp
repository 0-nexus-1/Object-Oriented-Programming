#include <iostream>
#include <string>
using namespace std;
                    // A-Solution

class XHO
{
protected:
    int a;
    int b;

public:
    XHO()
    {
        a = 8, b = 7;
    }
    XHO(int x, int y)
    {
        a = a + x;
        b = b - a;
        cout << b << endl;
        cout << y << endl;
    }
    ~XHO()
    {
        cout << "V M" << endl;
    }
};
class HOX : public XHO
{
private:
    int c;

public:
    HOX()
    {
        c = 4;
        a = a + c;
    }
    HOX(int a, int b, int c) : XHO(a, b)
    {
        cout << c + 7 << endl;
    }
    ~HOX()
    {
        cout << "S N" << endl;
    }
};
class HXO : public XHO, public HOX
{
public:
    HXO()
    {
        cout << "K L" << endl;
    }
    HXO(char m)
    {
        cout << "S P" << endl;
    }
    ~HXO()
    {
        cout << "X P" << endl;
    }
};
int main()
{
    HOX *h1 = new HOX(3, 4, 5);
    cout << "Mid" << endl;
    HXO *h2 = new HXO();
    delete h1;
    XHO *h3 = new XHO(9, 8);
    delete h2;
}
/*                      // B-Solution

class XHO
{
protected:
    int l;
    int m;

public:
    XHO()
    {
        l = 5, m = 2;
    }
    XHO(int x, int y)
    {
        l = y * x;
        m = l - x;
        cout << l + 1 << endl;
        cout << m - 2 << endl;
    }
    ~XHO()
    {
        cout << "V M" << endl;
    }
};
class HOX : public XHO
{
private:
    int c;

public:
    HOX()
    {
        c = 4;
        l = l * c;
    }
    HOX(int a, int b, int c) : XHO(a, b)
    {
        cout << "S K" << endl;
    }
    ~HOX()
    {
        cout << "K Y" << endl;
    }
};
class HXO : public XHO, public HOX
{
public:
    HXO()
    {
        cout << "S M" << endl;
    }
    HXO(float b)
    {
        cout << b << endl;
    }
    ~HXO()
    {
        cout << "A Z" << endl;
    }
};
int main()
{
    HXO *h1 = new HXO(3.4);
    HOX *h2 = new HOX();
    cout << "Mid" << endl;
    delete h1;
    XHO *h3 = new XHO(-2, 5);
    delete h3;
}*/
/*                      // C-Solution

class XHO
{
protected:
    int x;

public:
    XHO()
    {
        x = 5;
        cout << "K J" << endl;
    }
    XHO(int a)
    {
        x = a;
        cout << x - 2 << endl;
        cout << a - 1 << endl;
    }
    ~XHO()
    {
        cout << "D V" << endl;
    }
};
class OHX : public XHO
{
private:
    int c;

public:
    OHX()
    {
        c = 4;
    }
    OHX(int a, int b) : XHO(b)
    {
        cout << b + 2 << endl;
    }
    ~OHX()
    {
        cout << "A H" << endl;
    }
};
class HXO : public XHO, public OHX
{
public:
    HXO()
    {
        cout << "C M" << endl;
    }
    HXO(int b)
    {
        cout << b * 3 - b << endl;
    }
    ~HXO()
    {
        cout << "C B" << endl;
    }
};
int main()
{
    XHO *h1 = new XHO(8);
    HXO *h2 = new HXO(8.6);
    OHX *h3 = new OHX(3, 5);
    cout << "Mid" << endl;
    delete h1;
}*/
/*                      // D-Solution

class XHO
{
protected:
    int x;
    float y;

public:
    XHO()
    {
        x = 5;
        y = 5.3;
        cout << x + y << endl;
    }
    XHO(int a, float b)
    {
        y = b;
        cout << a * 2 << endl;
        cout << y - b << endl;
    }
    ~XHO()
    {
        cout << "M J" << endl;
    }
};
class OHX : public XHO
{
public:
    OHX()
    {
        cout << x + 2 << endl;
    }
    OHX(int a, int b, float c) : XHO(b, c)
    {
        cout << a + b + c << endl;
    }
    ~OHX()
    {
        cout << "D S" << endl;
    }
};
class HXO : public XHO, public OHX
{
public:
    HXO()
    {
        cout << 3 * 2 << endl;
    }
    HXO(int b)
    {
        cout << b * 2 - 3 << endl;
    }
    ~HXO()
    {
        cout << "Y T" << endl;
    }
};
int main()
{
    XHO *h1 = new XHO(8, 8.1);
    cout << "Mid" << endl;
    HXO *h2 = new HXO(8);
    OHX *h3 = new OHX(1, 2, 3.4);
    delete h3;
}*/
