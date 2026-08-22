#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    TrieNode* children[26] = {};
    string* word = nullptr;
};

class Solution {
private:
    void insert(TrieNode* root, string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->word = &word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* curr, vector<string>& result) {
        char ch = board[r][c];
        if (ch == '#' || !curr->children[ch - 'a']) return;

        curr = curr->children[ch - 'a'];
        if (curr->word) {
            result.push_back(*(curr->word));
            curr->word = nullptr; 
        }

        board[r][c] = '#';

        if (r > 0) dfs(board, r - 1, c, curr, result);
        if (r < board.size() - 1) dfs(board, r + 1, c, curr, result);
        if (c > 0) dfs(board, r, c - 1, curr, result);
        if (c < board[0].size() - 1) dfs(board, r, c + 1, curr, result);

        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& word : words) {
            insert(root, word);
        }

        vector<string> result;
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                dfs(board, r, c, root, result);
            }
        }

        return result;
    }
};

int main() {
    Solution solver;

    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };

    vector<string> words = {"oath", "pea", "eat", "rain"};

    vector<string> foundWords = solver.findWords(board, words);

    for (const string& word : foundWords) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
