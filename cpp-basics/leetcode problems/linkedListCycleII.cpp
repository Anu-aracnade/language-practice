#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};

int main() {
    ListNode *node1 = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(-4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;

    Solution solution;
    ListNode *cycleNode = solution.detectCycle(node1);

    if (cycleNode) {
        std::cout << "Tail connects to node index with value: " << cycleNode->val << std::endl;
    } else {
        std::cout << "No cycle" << std::endl;
    }

    node4->next = nullptr;
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}
