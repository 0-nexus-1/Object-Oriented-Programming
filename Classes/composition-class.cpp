#include <iostream>
using namespace std;

class Engine
{
private:
    int capacity;

public:
    Engine()
    {
        capacity = 0;
        cout << "DCtor of Engine\n";
    }

    Engine(int c)
    {
        capacity = c;
        cout << "PCtor of Engine\n";
    }

    void display()
    {
        cout << "Capacity: " << capacity << endl;
    }
};

class Car
{
private:
    int model;
    Engine *e[3];

public:
    Car()
    {
        model = 0;
        for (int i = 0; i < 3; i++)
        {
            e[i] = new Engine();
        }
        cout << "DCtro of Car\n";
    }

    Car(int m, Engine *e1[])
    {
        model = m;
        for (int i = 0; i < 3; i++)
        {
            e[i] = e1[i];
        }
        cout << "PCtro of Car\n";
    }

    void display()
    {
        for (int i = 0; i < 3; i++)
        {
            e[i]->display(); // Engine
        }
    }
};

int main()
{
    cout << "\n\t\tDate: " << __TIME__ << "\t\tTime: " << __DATE__ << endl
         << endl;

    Engine *engarr[3];
    engarr[0] = new Engine(800);
    engarr[1] = new Engine(1000);
    engarr[2] = new Engine(1300);

    Car *c = new Car(2019, engarr);

    c->display();
    cout << endl;
}
