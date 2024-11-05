// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Initialize dummy, slow and fast pointers to reach middle of linked list...
        ListNode dummy, *fast = &dummy, *slow = &dummy;
        dummy.next = head;
        // Find the middle of the linked list...
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Delete the middle node...
        slow->next = slow->next->next;
        return dummy.next;
    }
};