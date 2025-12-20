#include <stdio.h>
#include <stdlib.h>

/* Definition for singly-linked list */
struct ListNode {
    int val;
    struct ListNode *next;
};

/* LeetCode function */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (list1 && list2) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    tail->next = list1 ? list1 : list2;
    return dummy.next;
}

/* Helper: create linked list from user input */
struct ListNode* createList(int n) {
    struct ListNode *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d", &newNode->val);
        newNode->next = NULL;

        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

/* Helper: print linked list */
void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n1, n2;

    printf("Enter number of elements in first sorted list: ");
    scanf("%d", &n1);
    printf("Enter elements (sorted): ");
    struct ListNode* list1 = createList(n1);

    printf("Enter number of elements in second sorted list: ");
    scanf("%d", &n2);
    printf("Enter elements (sorted): ");
    struct ListNode* list2 = createList(n2);

    struct ListNode* merged = mergeTwoLists(list1, list2);

    printf("Merged sorted list: ");
    printList(merged);

    return 0;
}
