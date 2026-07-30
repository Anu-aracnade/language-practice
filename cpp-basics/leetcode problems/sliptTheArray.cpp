#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int count[101] = {0};
        for (int num : nums) {
            if (++count[num] > 2) {
                return false;
            }
        }
        return true;
    }
};
