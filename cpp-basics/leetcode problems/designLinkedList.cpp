#include <iostream>

class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int v) : val(v), next(nullptr) {}
    };
    
    Node* head;
    int size;

public:
    MyLinkedList() {
        head = new Node(-1);
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* curr = head->next;
        for (int i = 0; i < index; ++i) {
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head->next;
        head->next = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index < 0) index = 0;
        
        Node* curr = head;
        for (int i = 0; i < index; ++i) {
            curr = curr->next;
        }
        Node* newNode = new Node(val);
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        
        Node* curr = head;
        for (int i = 0; ++i <= index;) {
            curr = curr->next;
        }
        Node* toDelete = curr->next;
        curr->next = curr->next->next;
        delete toDelete;
        size--;
    }
    
    ~MyLinkedList() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }
    
    void printList() {
        Node* curr = head->next;
        std::cout << "List: ";
        while (curr != nullptr) {
            std::cout << curr->val << " -> ";
            curr = curr->next;
        }
        std::cout << "nullptr\n";
    }
};

int main() {
    MyLinkedList* obj = new MyLinkedList();
    
    obj->addAtHead(1);
    obj->printList();
    
    obj->addAtTail(3);
    obj->printList();
    
    obj->addAtIndex(1, 2);
    obj->printList();
    
    std::cout << "Get index 1: " << obj->get(1) << "\n";
    
    obj->deleteAtIndex(1);
    obj->printList();
    
    std::cout << "Get index 1: " << obj->get(1) << "\n";
    
    delete obj;
    return 0;
}
