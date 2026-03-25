#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of the array :";    
    cin >> n;
    cout << "Enter " << n << " elements :";
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(a[i], a[min]);
        }
        }
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
    }
    return 0;
}
