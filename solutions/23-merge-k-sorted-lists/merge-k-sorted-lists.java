/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
import java.util.PriorityQueue;

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }

        // Initialize Min-Heap: stores ListNodes, prioritized by their 'val'
        // The heap size is at most k.
        PriorityQueue<ListNode> pq = new PriorityQueue<>(
            lists.length, 
            (a, b) -> a.val - b.val
        );

        // 1. Populate the heap with the head of every non-empty list
        for (ListNode listHead : lists) {
            if (listHead != null) {
                pq.add(listHead);
            }
        }

        // Setup the merged list structure
        ListNode dummy = new ListNode(-1);
        ListNode current = dummy;

        // 2. Merge Loop
        while (!pq.isEmpty()) {
            // Extract the smallest node available
            ListNode minNode = pq.poll();
            
            // Append it to the merged list
            current.next = minNode;
            current = current.next;

            // If the extracted node has a next, add that to the heap
            if (minNode.next != null) {
                pq.add(minNode.next);
            }
        }

        return dummy.next;
    }
}