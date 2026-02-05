#include <iostream>
using namespace std;
class Solution {
public:
int strStr(string haystack , string needle){
    int n =haystack.length();
    int m = needle.length();
    if (n==0)
    return 0;
    if (n<m)
    return -1;
    for (int i =0; i<=n-m; i++){
        int j =0; // the pointer that works for needle indexing 
        while (j<m && haystack[i+j]==needle[j]){
            j++;
        }
        if (j==m){
            return i;
        }
    }
    return -1;
}
}str1,str2;

int main(){
    while(1){
    string a,b;
    cout<<"Enter the Haystack string : ";
    cin>>a;
    cout<<"Enter the needle string : ";
    cin>>b;
    int result = str1.strStr(a,b);
    cout<< "Index: "<<result<<endl;
    }
    return 0;
}