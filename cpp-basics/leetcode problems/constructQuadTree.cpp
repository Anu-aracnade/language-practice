#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
private:
    Node* helper(vector<vector<int>>& grid, int r, int c, int size) {
        if (size == 1) {
            return new Node(grid[r][c], true);
        }
        
        int half = size / 2;
        Node* topLeft = helper(grid, r, c, half);
        Node* topRight = helper(grid, r, c + half, half);
        Node* bottomLeft = helper(grid, r + half, c, half);
        Node* bottomRight = helper(grid, r + half, c + half, half);
        
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf &&
            topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val) {
            bool value = topLeft->val;
            delete topLeft;
            delete topRight;
            delete bottomLeft;
            delete bottomRight;
            return new Node(value, true);
        }
        
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        if (grid.empty()) return nullptr;
        return helper(grid, 0, 0, grid.size());
    }
};

void printQuadTree(Node* root) {
    if (!root) return;
    cout << "[" << root->isLeaf << ", " << root->val << "] ";
    if (!root->isLeaf) {
        printQuadTree(root->topLeft);
        printQuadTree(root->topRight);
        printQuadTree(root->bottomLeft);
        printQuadTree(root->bottomRight);
    }
}

void freeQuadTree(Node* root) {
    if (!root) return;
    if (!root->isLeaf) {
        freeQuadTree(root->topLeft);
        freeQuadTree(root->topRight);
        freeQuadTree(root->bottomLeft);
        freeQuadTree(root->bottomRight);
    }
    delete root;
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0}
    };

    Solution solver;
    Node* root = solver.construct(grid);

    printQuadTree(root);
    cout << endl;

    freeQuadTree(root);
    return 0;
}
