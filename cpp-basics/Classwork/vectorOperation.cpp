#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
vector<int> v={1,2,3,4,5};
v.push_back(6);
v.push_back(7);
v.pop_back();
v.erase(find(v.begin(),v.end(),2));
for (auto x:v){
    cout<<x<<" ";
}
return 0;
}