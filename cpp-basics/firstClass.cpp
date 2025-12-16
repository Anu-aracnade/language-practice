#include <iostream>
using namespace std;

class Animal
{
private:
    int a, b, c;

public:
    int d, e;
    void setNumber(int a1, int b1, int c1);
    void setSound()
    {
        cout << "Number of dogs in farm A is " << a << endl;
        cout << "Number of dogs in farm B is " << b << endl;
        cout << "Number of dogs in farm C is " << c << endl;
        cout << "Number of dogs in farm D is " << d << endl;
        cout << "Number of dogs in farm E is " << e << endl;
    }
};

void Animal ::setNumber(int a1, int b1, int c1)
{
    a = a1;
    b = b1;
    c = c1;
}

int main()
{
    Animal dog;
    // dog.b = 6; ---> This will thrown an errow as a is private.
    dog.d = 3;
    dog.e = 5;
    dog.setNumber(4, 8, 6);
    dog.setSound();
}