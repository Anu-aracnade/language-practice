#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int num = left; num <= right; ++num) {
            if (isSelfDividing(num)) {
                ans.push_back(num);
            }
        }
        return ans;
    }

private:
    bool isSelfDividing(int num) {
        for (int n = num; n > 0; n /= 10) {
            int digit = n % 10;
            if (digit == 0 || num % digit != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    int left = 1;
    int right = 22;
    
    vector<int> result = solution.selfDividingNumbers(left, right);
    
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
