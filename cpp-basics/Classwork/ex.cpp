#include <iostream>
using namespace std;
int main (){
    int index;
    cout<<"Enter index: ";
    cin>>index;
    try{
        accessArray(arr,5,index);
    }
    catch(int i){
        cout << "Exception :Index "<< i<<"is out of bounds !"<<endl;
    }
    return 0;
}