#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool isSquare(int x) {
        int r = sqrt(x);
        return r * r == x;
    }

    void dfs(vector<int>& nums, vector<bool>& vis, int last, int cnt, int& ans) {
        if (cnt == nums.size()) {
            ans++;
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (vis[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]) continue;
            if (last != -1 && !isSquare(last + nums[i])) continue;
            vis[i] = true;
            dfs(nums, vis, nums[i], cnt + 1, ans);
            vis[i] = false;
        }
    }

public:
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> vis(nums.size(), false);
        int ans = 0;
        dfs(nums, vis, -1, 0, ans);
        return ans;
    }
};

int main() {
    Solution solver;
    vector<int> nums = {1, 17, 8};
    cout << solver.numSquarefulPerms(nums) << endl;
    return 0;
}
