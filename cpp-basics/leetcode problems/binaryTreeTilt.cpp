#include <iostream>
#include <cmath>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(left), right(right) {}
};

class Solution {
public:
    int findTilt(TreeNode* root) {
        int totalTilt = 0;
        calculateSumAndTilt(root, totalTilt);
        return totalTilt;
    }

private:
    int calculateSumAndTilt(TreeNode* node, int& totalTilt) {
        if (!node) return 0;
        
        int leftSum = calculateSumAndTilt(node->left, totalTilt);
        int rightSum = calculateSumAndTilt(node->right, totalTilt);
        
        totalTilt += std::abs(leftSum - rightSum);
        
        return leftSum + rightSum + node->val;
    }
};

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7);

    Solution solution;
    int result = solution.findTilt(root);

    std::cout << result << std::endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
