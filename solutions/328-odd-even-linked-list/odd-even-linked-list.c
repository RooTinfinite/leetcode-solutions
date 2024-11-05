/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* odd = (struct ListNode*)malloc(sizeof(struct ListNode));
    odd->val = 0;
    odd->next = NULL;
    struct ListNode* odd_ptr = odd;
    struct ListNode* even = (struct ListNode*)malloc(sizeof(struct ListNode));
    even->val = 0;
    even->next = NULL;
    struct ListNode* even_ptr = even;
    int idx = 1;
    
    while (head != NULL) {
        if (idx % 2 == 0) {
            even_ptr->next = head;
            even_ptr = even_ptr->next;
        } else {
            odd_ptr->next = head;
            odd_ptr = odd_ptr->next;
        }
        head = head->next;
        idx++;
    }
    even_ptr->next = NULL; 
    odd_ptr->next = even->next;
    struct ListNode* newHead = odd->next; 
    free(odd);
    free(even);
    
    return newHead;
}