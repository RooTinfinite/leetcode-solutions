# Time complexity: O(n)
# Space complexity: O(1)
class Solution(object):
    def deleteMiddle(self, head):
        # Initialize dummy, slow and fast pointers to reach middle of linked list...
        dummy = ListNode(0, head)
        slow = dummy
        fast = dummy
        # Find the middle of the linked list...
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        # Delete the middle node...
        slow.next = slow.next.next
        return dummy.next