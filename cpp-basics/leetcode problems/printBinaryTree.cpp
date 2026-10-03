#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

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
    vector<vector<string>> printTree(TreeNode* root) {
        int h = getHeight(root);
        int m = h + 1;
        int n = (1 << (h + 1)) - 1;
        vector<vector<string>> ans(m, vector<string>(n, ""));
        fillTree(root, ans, 0, (n - 1) / 2, h);
        return ans;
    }

private:
    int getHeight(TreeNode* root) {
        if (!root) return -1;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    void fillTree(TreeNode* root, vector<vector<string>>& ans, int r, int c, int h) {
        if (!root) return;
        ans[r][c] = to_string(root->val);
        if (root->left) {
            fillTree(root->left, ans, r + 1, c - (1 << (h - r - 1)), h);
        }
        if (root->right) {
            fillTree(root->right, ans, r + 1, c + (1 << (h - r - 1)), h);
        }
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);

    Solution solver;
    vector<vector<string>> result = solver.printTree(root);

    for (const auto& row : result) {
        for (const auto& cell : row) {
            if (cell.empty()) {
                cout << "\"\" ";
            } else {
                cout << cell << " ";
            }
        }
        cout << "\n";
    }

    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
