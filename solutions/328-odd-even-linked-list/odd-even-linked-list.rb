# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val = 0, _next = nil)
#         @val = val
#         @next = _next
#     end
# end
# @param {ListNode} head
# @return {ListNode}
def odd_even_list(head)
    return head if head == nil || head.next == nil
    odd = ListNode.new(0) 
    odd_ptr = odd
    even = ListNode.new(0)
    even_ptr = even 
    idx = 1 
    while head != nil
        if idx % 2 == 0
            even_ptr.next = head
            even_ptr = even_ptr.next
        else
            odd_ptr.next = head
            odd_ptr = odd_ptr.next
        end
    head = head.next
    idx+=1
    end
    even_ptr.next = nil
    odd_ptr.next = even.next
    return odd.next
end