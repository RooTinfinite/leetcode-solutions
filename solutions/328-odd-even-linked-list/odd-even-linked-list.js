/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var oddEvenList = function(head) {
    if (head === null || head.next === null) return head;
    
    let odd = new ListNode(0);
    let odd_ptr = odd;
    let even = new ListNode(0);
    let even_ptr = even;
    let idx = 1;
    
    while (head !== null) {
        if (idx % 2 === 0) {
            even_ptr.next = head;
            even_ptr = even_ptr.next;
        } else {
            odd_ptr.next = head;
            odd_ptr = odd_ptr.next;
        }
        head = head.next;
        idx++;
    }
    
    even_ptr.next = null;
    odd_ptr.next = even.next;
    
    return odd.next;
};