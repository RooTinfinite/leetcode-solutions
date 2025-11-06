/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = head;
    struct ListNode* prevNode = dummy;
    while (head != NULL && head->next != NULL) {
        struct ListNode* firstNode = head;
        struct ListNode* secondNode = head->next;
        prevNode->next = secondNode;
        firstNode->next = secondNode->next;
        secondNode->next = firstNode;
        prevNode = firstNode;
        head = firstNode->next;
    }
    return dummy->next;
}