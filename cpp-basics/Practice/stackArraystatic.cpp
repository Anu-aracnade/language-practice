#include <iostream>
using namespace std;
#define MAX 6
class Stack
{
    int arr[MAX];
    int top = -1;

public:
    Stack()
    {
        top = -1;
    }
    void push(int x)
    {
        if (top == MAX - 1)
        {
            cout << "The stack is in overflow condition" << endl;
        }
        arr[++top] = x;
        cout<<x<<" has been pushed in the stack\n";
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "The stack is in underflow condition" << endl;
        }
        else
        {
            cout<<arr[top--]<<" has been popped in the stack\n"<<endl;
            }
    }
    void peek(){
        if(top==-1){
            cout<<"The stack is empty"<<endl;
        }
        else{
            cout<<arr[top]<<" is the top element of the stack"<<endl;
        }
    }
    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty";
        }
        else
        {
            cout << "\nStack elements: ";
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Stack st;
    st.push(10);
    st.push(11);
    st.push(12);
    st.push(13);
    st.push(14);
    st.push(15);
    st.display();
    st.pop();
    st.peek();
    st.pop();
    st.display();
}
