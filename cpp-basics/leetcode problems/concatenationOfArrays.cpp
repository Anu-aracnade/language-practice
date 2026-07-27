#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public: 
    vector<int> getConcatenation(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(2*n);
        for (int i=0;i<n;++i){
            ans[i]=nums[i];
            ans[i+n]=nums[i];
        }
        return ans;
    }
};
int main() {
    Solution solution;
    
    int size;
    cout<<"Enter the size of the array:"<<endl;
    cin>>size;
    vector<int> nums(size);
    cout<<"Enter "<<size<<" digits:"<<endl;
    for(int i=0;i<size;++i){
        cin>>nums[i];
    }
    
    vector<int> result = solution.getConcatenation(nums);
    cout<<"Concatenated result:";
    for (int x: result){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}