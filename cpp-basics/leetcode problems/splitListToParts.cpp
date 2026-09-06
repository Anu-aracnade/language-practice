#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* curr = head;
        while (curr) {
            len++;
            curr = curr->next;
        }

        int base_size = len / k;
        int extra = len % k;

        vector<ListNode*> res(k, nullptr);
        curr = head;

        for (int i = 0; i < k && curr; i++) {
            res[i] = curr;
            int part_size = base_size + (i < extra ? 1 : 0);
            
            for (int j = 1; j < part_size; j++) {
                curr = curr->next;
            }
            
            ListNode* next_part = curr->next;
            curr->next = nullptr;
            curr = next_part;
        }

        return res;
    }
};

void printList(ListNode* head) {
    if (!head) {
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    while (head) {
        cout << head->val;
        if (head->next) cout << ",";
        head = head->next;
    }
    cout << "]" << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next->next->next->next->next = new ListNode(10);

    int k = 3;

    Solution solver;
    vector<ListNode*> result = solver.splitListToParts(head, k);

    for (int i = 0; i < k; i++) {
        cout << "Part " << i + 1 << ": ";
        printList(result[i]);
    }

    for (ListNode* part : result) {
        while (part) {
            ListNode* temp = part;
            part = part->next;
            delete temp;
        }
    }

    return 0;
}
