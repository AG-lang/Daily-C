#include <stdio.h>
#include<malloc.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* oddEvenList(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }
    struct ListNode* evenHead = head->next;
    struct ListNode* odd = head;
    struct ListNode* even = evenHead;
    while (even != NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

// Helper function to print the linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Example usage
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next->next->next->next = NULL;

    printf("Original List: ");
    printList(head);

    head = oddEvenList(head);

    printf("Modified List: ");
    printList(head);

    return 0;
}
