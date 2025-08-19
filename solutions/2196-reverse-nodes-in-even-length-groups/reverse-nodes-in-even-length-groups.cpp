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
private:
    ListNode* reverseGroups(ListNode *before, int group_node) {
        // Keep track of last node
        ListNode* returnNode = before->next;
        ListNode* prev = before;
        ListNode* curr = before->next;
        for (int i = 0; i < group_node; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // current node should be node after right node; prev node is right node
        // Adjust node on left to link to the current and prev node.
        before->next->next = curr;
        before->next = prev;
        return returnNode;
    }
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        // First group we don't need reverse
        ListNode* before = head;
        ListNode* curr = before->next;
        // Start with group 2 and initialize counter
        int group = 2;
        int count_group = 1;

        while (curr) {
            // Find the current group size
            while (curr->next && count_group < group) {
                curr = curr->next;
                count_group++;
            }

            if (count_group % 2) {
                // Odd group - jump directly to the current node
                before = curr;
            } else {
                // reverse the subgroup using last node in previous group
                before = reverseGroups(before, count_group);
            }
            
            // Update the current node to first node of next group
            curr = before->next;
            // Reset the counter and update expected next group size
            count_group = 1;
            group++;
        }
        return head;
    }
};