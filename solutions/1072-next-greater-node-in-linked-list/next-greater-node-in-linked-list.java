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
import java.util.*;

class Solution {
    public int[] nextLargerNodes(ListNode head) {
        // Step 1: Convert Linked List to ArrayList for random access
        List<Integer> values = new ArrayList<>();
        while (head != null) {
            values.add(head.val);
            head = head.next;
        }

        int[] answer = new int[values.size()];
        Stack<Integer> stack = new Stack<>(); // Stores INDICES

        // Step 2: Iterate through the values
        for (int i = 0; i < values.size(); i++) {
            // Step 3: Check if current value is greater than values at stack indices
            while (!stack.isEmpty() && values.get(i) > values.get(stack.peek())) {
                int index = stack.pop();
                answer[index] = values.get(i);
            }
            // Step 4: Push current index onto stack
            stack.push(i);
        }

        return answer;
    }
}