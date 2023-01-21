#include <iostream>
#include <string>
using namespace std;

class A
{
protected:
    int a;

public:
    A()
    {
        cout << "Default Constructor of A: ";
    }
    A(int n)
    {
        a = n;
    }

    ~A()
    {
        cout << a + 2 << " ";
    }
};
class B : public A
{
protected:
    int b;

public:
    B(int n1, int n2)
    {
        b = n1, a = 10;
    }

    ~B()
    {
        cout << a << " " << b << " ";
    }
};

class C : public B
{
protected:
    int c;

public:
    C(int n1, int n2, int n3) : B(n2, n3)
    {
        a = 79, b = 10;
        c = n1;
    }
    ~C()
    {
        cout << b << " " << c << " ";
    }
};
class D : public C
{
private:
    int d;

public:
    D(int n1, int n2, int n3, int n4) : C(n1, n2, n3)
    {
        d = n1;
    }
    ~D()
    {
        cout << a << " " << b << " " << c << " "
             << " " << d << " ";
    }
};

int main()
{
    D a(2, 3, 4, 5);
}
