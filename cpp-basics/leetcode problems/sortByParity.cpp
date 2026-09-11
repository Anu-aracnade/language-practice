#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            if (nums[left] % 2 > nums[right] % 2) {
                swap(nums[left], nums[right]);
            }
            if (nums[left] % 2 == 0) left++;
            if (nums[right] % 2 != 0) right--;
        }
        
        return nums;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 1, 2, 4};
    
    vector<int> result = solution.sortArrayByParity(nums);
    
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
