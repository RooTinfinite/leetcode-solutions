# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head or not head.next:
            return

        # --- Step 1: Find the Middle ---
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        # 'slow' is now at the middle (or end of first half)
        # We split the list here.
        second_half = slow.next
        slow.next = None # Cut off the first half from the second
        
        # --- Step 2: Reverse the Second Half ---
        prev = None
        curr = second_half
        
        while curr:
            temp_next = curr.next # Save next node
            curr.next = prev      # Reverse pointer
            prev = curr           # Move prev forward
            curr = temp_next      # Move curr forward
            
        # 'prev' is now the head of the reversed second half
        second = prev
        first = head
        
        # --- Step 3: Merge the Two Halves ---
        # We merge until the second list is empty (it is always shorter or equal length)
        while second:
            # Save the next pointers for both lists
            tmp1, tmp2 = first.next, second.next
            
            # Link first -> second
            first.next = second
            # Link second -> (original) next of first
            second.next = tmp1
            
            # Move pointers forward
            first = tmp1
            second = tmp2