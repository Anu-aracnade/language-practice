#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int max_dist = 0;
        int min_val = arrays[0].front();
        int max_val = arrays[0].back();
        for (size_t i = 1; i < arrays.size(); ++i) {
            max_dist = max({max_dist, arrays[i].back() - min_val, max_val - arrays[i].front()});
            min_val = min(min_val, arrays[i].front());
            max_val = max(max_val, arrays[i].back());
        }
        return max_dist;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> arrays = {
        {1, 2, 3},
        {4, 5},
        {1, 2, 3}
    };
    Solution solver;
    int result = solver.maxDistance(arrays);
    cout << result << "\n";
    return 0;
}
