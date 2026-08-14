#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        result.reserve(word1.length() + word2.length());
        int i = 0;
        while (i < word1.length() && i < word2.length()) {
            result.push_back(word1[i]);
            result.push_back(word2[i]);
            i++;
        }
        if (i < word1.length()) {
            result.append(word1.substr(i));
        } else if (i < word2.length()) {
            result.append(word2.substr(i));
        }
        return result;
    }
};

int main() {
    Solution solution;
    
    string word1 = "abc";
    string word2 = "pqr";
    cout << solution.mergeAlternately(word1, word2) << endl;
    
    word1 = "ab";
    word2 = "rs";
    cout << solution.mergeAlternately(word1, word2) << endl;
    
    return 0;
}
