#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> parent;
    
    int findParent(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = findParent(parent[i]);
    }
    
    void unionNodes(int i, int j) {
        int rootI = findParent(i);
        int rootJ = findParent(j);
        if (rootI != rootJ) {
            parent[rootI] = rootJ;
        }
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        unordered_map<string, int> emailToAccIdx;
        for (int i = 0; i < n; ++i) {
            for (size_t j = 1; j < accounts[i].size(); ++j) {
                string email = accounts[i][j];
                if (emailToAccIdx.find(email) == emailToAccIdx.end()) {
                    emailToAccIdx[email] = i;
                } else {
                    unionNodes(i, emailToAccIdx[email]);
                }
            }
        }

        unordered_map<int, vector<string>> mergedAccounts;
        for (auto& it : emailToAccIdx) {
            string email = it.first;
            int accIdx = it.second;
            int rootIdx = findParent(accIdx);
            mergedAccounts[rootIdx].push_back(email);
        }

        vector<vector<string>> result;
        for (auto& it : mergedAccounts) {
            int rootIdx = it.first;
            vector<string> emails = it.second;
            sort(emails.begin(), emails.end());
            
            vector<string> account;
            account.push_back(accounts[rootIdx][0]);
            account.insert(account.end(), emails.begin(), emails.end());
            result.push_back(account);
        }

        return result;
    }
};

int main() {
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}
    };

    Solution solver;
    vector<vector<string>> mergedAccounts = solver.accountsMerge(accounts);

    for (const auto& account : mergedAccounts) {
        cout << account[0] << ": ";
        for (size_t i = 1; i < account.size(); ++i) {
            cout << account[i] << (i == account.size() - 1 ? "" : ", ");
        }
        cout << endl;
    }

    return 0;
}
