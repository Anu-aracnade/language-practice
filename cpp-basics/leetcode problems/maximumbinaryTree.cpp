#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> stk;
        for (int num : nums) {
            TreeNode* curr = new TreeNode(num);
            while (!stk.empty() && stk.back()->val < num) {
                curr->left = stk.back();
                stk.pop_back();
            }
            if (!stk.empty()) {
                stk.back()->right = curr;
            }
            stk.push_back(curr);
        }
        return stk.empty() ? nullptr : stk.front();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 1, 6, 0, 5};
    TreeNode* root = sol.constructMaximumBinaryTree(nums);
    return 0;
}
