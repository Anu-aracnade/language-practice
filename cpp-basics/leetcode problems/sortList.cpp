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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        int length = 0;
        ListNode* curr = head;
        while (curr) {
            length++;
            curr = curr->next;
        }
        
        ListNode dummy(0);
        dummy.next = head;
        
        for (int step = 1; step < length; step <<= 1) {
            ListNode* prev = &dummy;
            curr = dummy.next;
            
            while (curr) {
                ListNode* left = curr;
                ListNode* right = split(left, step);
                curr = split(right, step);
                prev = merge(left, right, prev);
            }
        }
        
        return dummy.next;
    }

private:
    ListNode* split(ListNode* head, int step) {
        if (!head) return nullptr;
        for (int i = 1; head->next && i < step; ++i) {
            head = head->next;
        }
        ListNode* rest = head->next;
        head->next = nullptr;
        return rest;
    }

    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* prev) {
        while (l1 && l2) {
            if (l1->val < l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        prev->next = l1 ? l1 : l2;
        while (prev->next) {
            prev = prev->next;
        }
        return prev;
    }
};

ListNode* createList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < values.size(); ++i) {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << "\n";
}

void freeList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    std::vector<int> values = {4, 2, 1, 3, 5, -1, 0};
    
    ListNode* head = createList(values);
    
    Solution solution;
    head = solution.sortList(head);
    
    printList(head);
    
    freeList(head);
    
    return 0;
}
