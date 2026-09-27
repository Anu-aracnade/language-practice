#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1;
        int current_width = 0;
        
        for (char c : s) {
            int w = widths[c - 'a'];
            if (current_width + w > 100) {
                lines++;
                current_width = w;
            } else {
                current_width += w;
            }
        }
        
        return {lines, current_width};
    }
};

int main() {
    vector<int> widths = {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    string s = "abcdefghijklmnopqrstuvwxyz";
    
    Solution solver;
    vector<int> result = solver.numberOfLines(widths, s);
    
    cout << result[0] << " " << result[1] << endl;
    
    return 0;
}
