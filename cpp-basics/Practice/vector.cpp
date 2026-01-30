#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v = {11, 22, 33, 44, 55};
    cout << "The elements in our vector are :";
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "The size of the vector : " << v.size() << endl; // with the help of this function you get to know the size of the vector
    cout << "The capacity of the vector : " << v.capacity() << endl;

    while (1)
    {
        int a;
        cout << "\nEnter an element you want to add at the end of the vector :";
        cin >> a;
        v.push_back(a);
        cout << "The new vector elements are: ";
        for (int x : v)
        {
            cout << x << " ";
        }
    }
    return 0;
}