#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        int carry = 0;
        
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }
        
        return dummy.next;
    }
};

int main() {
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    ListNode* temp = result;
    while (temp) {
        std::cout << temp->val << (temp->next ? " -> " : "");
        temp = temp->next;
    }
    std::cout << std::endl;

    while (l1) {
        ListNode* next = l1->next;
        delete l1;
        l1 = next;
    }
    while (l2) {
        ListNode* next = l2->next;
        delete l2;
        l2 = next;
    }
    while (result) {
        ListNode* next = result->next;
        delete result;
        result = next;
    }

    return 0;
}
