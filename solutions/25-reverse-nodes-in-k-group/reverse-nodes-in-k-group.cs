/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode ReverseLinkedList(ListNode head, int k) {
        ListNode new_head = null;
        ListNode ptr = head;
        while (k > 0) {
            ListNode next_node = ptr.next;
            ptr.next = new_head;
            new_head = ptr;
            ptr = next_node;
            k--;
        }

        return new_head;
    }

    public ListNode ReverseKGroup(ListNode head, int k) {
        int count = 0;
        ListNode ptr = head;
        while (count < k && ptr != null) {
            ptr = ptr.next;
            count++;
        }

        if (count == k) {
            ListNode reversedHead = this.ReverseLinkedList(head, k);
            head.next = this.ReverseKGroup(ptr, k);
            return reversedHead;
        }

        return head;
    }
}