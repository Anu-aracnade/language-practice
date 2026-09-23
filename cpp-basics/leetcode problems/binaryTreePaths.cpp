#include <iostream>
#include <vector>
#include <string>

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
    void dfs(TreeNode* node, string path, vector<string>& paths) {
        if (!node) return;
        path += to_string(node->val);
        if (!node->left && !node->right) {
            paths.push_back(path);
        } else {
            path += "->";
            dfs(node->left, path, paths);
            dfs(node->right, path, paths);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        dfs(root, "", paths);
        return paths;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution solver;
    vector<string> result = solver.binaryTreePaths(root);

    for (const string& path : result) {
        cout << path << endl;
    }

    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
