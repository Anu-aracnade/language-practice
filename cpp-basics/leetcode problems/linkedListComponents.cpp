#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int numComponents(ListNode* head, std::vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        
        bool present[10001] = {false};
        for (int num : nums) {
            present[num] = true;
        }
        
        int count = 0;
        bool in_component = false;
        
        while (head) {
            if (present[head->val]) {
                if (!in_component) {
                    in_component = true;
                    count++;
                }
            } else {
                in_component = false;
            }
            head = head->next;
        }
        
        return count;
    }
};

int main() {
    ListNode* node4 = new ListNode(3);
    ListNode* node3 = new ListNode(2, node4);
    ListNode* node2 = new ListNode(1, node3);
    ListNode* head = new ListNode(0, node2);
    
    std::vector<int> nums = {0, 1, 3};
    
    Solution solver;
    int result = solver.numComponents(head, nums);
    
    std::cout << result << std::endl;
    
    delete head;
    delete node2;
    delete node3;
    delete node4;
    
    return 0;
}
