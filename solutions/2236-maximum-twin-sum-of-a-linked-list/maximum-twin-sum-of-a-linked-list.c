/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode* head) {
    int temp[100000];
    int size = 0;
    struct ListNode* node = head;
    while (node) {
        temp[size++] = node->val;
        node = node->next;
    }
    node = head;
    int res = -2147483648;
    for (int i = 0; i < size / 2; i++) {
        int sum = node->val + temp[size - 1 - i];
        if (sum > res) res = sum;
        node = node->next;
    }
    return res;
}