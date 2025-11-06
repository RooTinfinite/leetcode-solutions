/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Dummy node acts as the prevNode for the head node
        // of the list and hence stores pointer to the head node.
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prevNode = dummy;
        while ((head != nullptr) && (head->next != nullptr)) {
            // Nodes to be swapped
            ListNode* firstNode = head;
            ListNode* secondNode = head->next;
            // Swapping
            prevNode->next = secondNode;
            firstNode->next = secondNode->next;
            secondNode->next = firstNode;
            // Reinitializing the head and prevNode for next swap
            prevNode = firstNode;
            head = firstNode->next;  // jump
        }
        // Return the new head node.
        return dummy->next;
    }
};