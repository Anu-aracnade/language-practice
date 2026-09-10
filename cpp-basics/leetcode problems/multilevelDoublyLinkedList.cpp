#include <iostream>

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        
        Node* curr = head;
        while (curr) {
            if (curr->child) {
                Node* nextNode = curr->next;
                Node* childHead = flatten(curr->child);
                
                curr->next = childHead;
                childHead->prev = curr;
                curr->child = nullptr;
                
                Node* childTail = childHead;
                while (childTail->next) {
                    childTail = childTail->next;
                }
                
                childTail->next = nextNode;
                if (nextNode) {
                    nextNode->prev = childTail;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};

void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

void freeList(Node* head) {
    Node* curr = head;
    while (curr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    Node* childHead = new Node(7);
    childHead->next = new Node(8);
    childHead->next->prev = childHead;

    head->next->child = childHead;

    Solution solver;
    Node* flattenedHead = solver.flatten(head);

    printList(flattenedHead);
    freeList(flattenedHead);

    return 0;
}
