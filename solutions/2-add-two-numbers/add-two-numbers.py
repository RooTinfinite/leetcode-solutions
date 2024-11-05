class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        carry = 0
        dummy = ListNode(-1)
        cur = dummy

        while l1 or l2:
            x1 = l1.val if l1 else 0
            x2 = l2.val if l2 else 0
            partial_sum = (x1+x2+carry)
            cur.next = ListNode(partial_sum%10)
            carry = partial_sum // 10
            if l1: 
                l1 = l1.next
            if l2:
                l2 = l2.next
            
            cur = cur.next
        if carry:
            cur.next = ListNode(carry)
            cur = cur.next
        cur.next = None
        return dummy.next