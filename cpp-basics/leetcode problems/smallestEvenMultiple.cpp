#include <iostream>

class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n % 2 == 0 ? n : n * 2;
    }
};

int main() {
    Solution sol;
    int n = 5;
    std::cout << sol.smallestEvenMultiple(n) << std::endl;
    return 0;
}
