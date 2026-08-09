#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }
        return sum;
    }
};

int main() {
    int n;
    if (!(cin >> n)) {
        return 0;
    }

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        if (!(cin >> nums[i])) {
            return 0;
        }
    }

    Solution solution;
    cout << solution.arrayPairSum(nums) << '\n';
    return 0;
}
