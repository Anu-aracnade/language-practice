#include <iostream>
using namespace std;
class Stack{
private: 
int *arr;
int capacity;
int top;

public : 
    Stack(int cap){
        capacity = cap;
        arr= new int[capacity];
        top=-1;
    }

    void push(int x){
        if (top==capacity-1){
            cout<<"The Stack is in overflow condition"<<endl;
            return;
            }
            arr[++top]=x; // ++top means top=top+1 increasing the array size and also associating with the new top element
    }
    int pop(){
        if (top==-1){
            cout<<"The Stack is in underflow condition"<<endl;
            return -1;
        }
        return arr[top--];
    }
};
int main(){
    Stack st(5);
    st.push(12);
    st.push(13);
    st.push(14);
    st.push(15);
    st.push(16);
    cout<<"Popped: "<<st.pop()<<endl;
    return 0;
}
