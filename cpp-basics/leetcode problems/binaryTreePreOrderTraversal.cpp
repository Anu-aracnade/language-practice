#include <iostream>
#include <vector>

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* current = root;
        while (current) {
            if (!current->left) {
                result.push_back(current->val);
                current = current->right;
            } else {
                TreeNode* predecessor = current->left;
                while (predecessor->right && predecessor->right != current) {
                    predecessor = predecessor->right;
                }
                if (!predecessor->right) {
                    result.push_back(current->val);
                    predecessor->right = current;
                    current = current->left;
                } else {
                    predecessor->right = nullptr;
                    current = current->right;
                }
            }
        }
        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution;
    vector<int> output = solution.preorderTraversal(root);

    for (int val : output) {
        cout << val << " ";
    }
    cout << endl;

    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
