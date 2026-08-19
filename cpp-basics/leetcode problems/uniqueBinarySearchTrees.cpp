#include <iostream>

class Solution {
public:
    int numTrees(int n) {
        long long c = 1;
        for (int i = 0; i < n; ++i) {
            c = c * 2 * (2 * i + 1) / (i + 2);
        }
        return (int)c;
    }
};

int main() {
    Solution solver;
    int n = 3;
    std::cout << solver.numTrees(n) << std::endl;
    return 0;
}
