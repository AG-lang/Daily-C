#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to create a new ListNode
struct ListNode* createNode(int x) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = x;
    node->next = NULL;
    return node;
}

// Function to find the middle node of a linked list
struct ListNode* middleNode(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to print the linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Example usage
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    // int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    struct ListNode* head = createNode(arr[0]);
    struct ListNode* current = head;

    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }

    printf("Original List: ");
    printList(head);

    struct ListNode* result = middleNode(head);

    printf("Middle Node: %d\n", result->val);

    return 0;
}
