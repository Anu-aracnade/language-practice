#include <iostream>
using namespace std;
int main(){
    int num1,num2;
    cout<<"Enter two integers: ";
    cin>>num1>>num2;
    try{
        if (num2== 0){
            throw"Error: Division by zero is not allowed!";
        }
        float result = (float)num1/num2;
        }
        catch (const char*msg){
            cout<<msg<<endl;
        }
    return 0;
}