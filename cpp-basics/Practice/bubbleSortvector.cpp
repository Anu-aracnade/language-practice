#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of element for the vector :";
    cin>>n;
    vector<int> vec;
    cout<<"Enter "<<n<<"elements for the vector :"<<endl;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        vec.push_back(t);
    }
    cout<<"You entered: ";
    for(int x:vec){
        cout<<x<<" ";        
    }
    int temp;
    cout<<"\n\n";
    cout<<"----After bubble sort----"<<endl;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(vec[j]>vec[j+1]){
                temp=vec[j];
                vec[j]=vec[j+1];
                vec[j+1]=temp;
            }
        }
    }
    for(int x:vec){
        cout<<x<<" ";
    }
    return 0;
}