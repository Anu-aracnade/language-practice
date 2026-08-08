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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode** curr = &head;
        while (*curr) {
            if ((*curr)->val == val) {
                ListNode* temp = *curr;
                *curr = (*curr)->next;
                delete temp;
            } else {
                curr = &((*curr)->next);
            }
        }
        return head;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    Solution solution;
    head = solution.removeElements(head, 6);

    ListNode* curr = head;
    while (curr) {
        std::cout << curr->val << " ";
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
    std::cout << "\n";

    return 0;
}
