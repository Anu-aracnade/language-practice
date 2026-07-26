#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
              vector<int> counts(1001, 0);
              vector<int> result;        
              for (const auto& row : nums) {
              for (int num : row) {
                counts[num]++;
              }
              }        
              for (int i = 1; i <= 1000; ++i) {
              if (counts[i] == nums.size()) {
                result.push_back(i);
            }
        }
        return result;  
    }
};