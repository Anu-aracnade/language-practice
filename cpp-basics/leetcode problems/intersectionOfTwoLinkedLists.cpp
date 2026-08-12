
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        
        ListNode *ptrA = headA;
        ListNode *ptrB = headB;
        
        while (ptrA != ptrB) {
            ptrA = ptrA ? ptrA->next : headB;
            ptrB = ptrB ? ptrB->next : headA;
        }
        
        return ptrA;
    }
};

int main() {
    ListNode *common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    Solution solver;
    ListNode *intersection = solver.getIntersectionNode(headA, headB);

    if (intersection) {
        std::cout << "Intersected at '" << intersection->val << "'" << std::endl;
    } else {
        std::cout << "No intersection" << std::endl;
    }

    delete headA->next;
    delete headA;

    delete headB->next->next;
    delete headB->next;
    delete headB;

    while (common) {
        ListNode *temp = common->next;
        delete common;
        common = temp;
    }

    return 0;
}
