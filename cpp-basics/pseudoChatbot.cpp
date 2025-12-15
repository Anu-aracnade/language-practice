#include <iostream>
using namespace std;
//............. Function for addition..................
int runningSum(int *S, int c)
{
    int sum = 0;
    for (int i = 0; i < c; i++)
    {
        sum += S[i];
    }
    return sum;
}

int main()
{
    char a;
    while (1) //.................... The chatbot talking begins
    {
        cout << "Hello my name is Anubhab, your buddy ;)" << endl;

        cout << "Tell me about yourself ? Are you fine ? (Y/N)" << endl;
        cin >> a;
        if (a == 'Y')
        {
            cout << "Nice, it's good to hear that . Do you want to plan your day with me ?" << endl;
        }
        else if (a == 'N')
        {
            cout << "It's sad to hear that , but why man ? what the hell is wrong is with you ?  " << endl;
        }
        else
        {
            cout << "Are you mad! What are you typing ?" << endl
                 << "Okay forget it, do you want me to add some numbers for you? I think so that can make you happy, what do you think ? (Y/N) " << endl;
            break;
        }
    }
    //............................ Using array and loop concept for adding some numbers
    cin >> a;
    if (a == 'Y')
    {
        int b;
        cout << "Okay go for it , how many numbers do you want to add?" << endl;
        cin >> b;
        int A[b];
        cout << "Okay!,done." << endl;
        for (int i = 0; i < b; i++)
        {
            cout << "Enter your " << i + 1 << " th number :";
            cin >> A[i];
        }
        int result = runningSum(A, b);
        cout << "There you go, the sum is :" << result << endl;
    }
    else
    {
        cout << "Okay I get it , your mood is bad ,but I am trying to help na ... why don't you understand ?" << endl;
    }
    return 0;
}
