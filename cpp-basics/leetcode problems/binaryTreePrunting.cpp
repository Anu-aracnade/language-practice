#include <iostream>

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
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->val == 0 && !root->left && !root->right) {
            delete root;
            return nullptr;
        }
        return root;
    }
};

void printInorder(TreeNode* node) {
    if (!node) {
        return;
    }
    printInorder(node->left);
    std::cout << node->val << " ";
    printInorder(node->right);
}

void freeTree(TreeNode* node) {
    if (!node) {
        return;
    }
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(0);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);

    Solution solution;
    root = solution.pruneTree(root);

    printInorder(root);
    std::cout << std::endl;

    freeTree(root);
    return 0;
}
