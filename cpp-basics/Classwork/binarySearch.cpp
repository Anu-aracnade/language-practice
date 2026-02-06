#include <iostream>
using namespace std;
int main(){
int n;
cin>>n;
int A[n];
for(int i =0;i<n;i++){
    cin>>A[i];
}
int target;
    cin>>target;
int left =0;
int right=n-1;
bool found = false;
while (left<=right){
    int mid=left+(right-left)/2;
    if (A[mid] == target){
        cout<<mid;
        found=true;
        break;
    }
    else if (A[mid] < target){
        left=mid +1;
    }
    else{
        right=mid-1;
    }
    }
    if (!found){
        cout<<"Not found";
    }
return 0;}