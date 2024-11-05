/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode OddEvenList(ListNode head) {
        if(head == null || head.next == null)return head;
        ListNode odd = new ListNode(0);
        ListNode odd_ptr = odd;
        ListNode even = new ListNode(0);
        ListNode even_ptr = even;
        int idx = 1;
        while(head != null){
            if(idx % 2 == 0){
                even_ptr.next = head;
                even_ptr = even_ptr.next;
            }else{
                odd_ptr.next = head;
                odd_ptr = odd_ptr.next;
            }
            head = head.next;
            idx++;
        }
        even_ptr.next = null;
        odd_ptr.next = even.next; 
        return odd.next;
    }
}