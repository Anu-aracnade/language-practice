#include <iostream>
using namespace std;
int main(){
int n;
cout<<"Enter the size of array :";
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cout<<"Enter your "<<i<<" index element of the array :";
    cin>>arr[i];
}
cout<<"Your entered array is :";
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
int temp;
for (int i=0;i<n-1;i++){
    for (int j=0;j<n-i-1;i++){
        if(arr[j]>arr[j+1]){
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
    }
}
}
cout<<"The sorted array is : ";
for (int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
    return 0;
}