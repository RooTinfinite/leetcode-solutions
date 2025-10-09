import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashSet;
import java.util.Set;

class Solution {
    public int minOperations(int[] nums) {
        int ans = 0;
        Deque<Integer> stack = new ArrayDeque<>();
        for (int i = nums.length - 1; i >= 0; i--) {
            Set<Integer> set = new HashSet<>();
            while (!stack.isEmpty() && stack.peek() > nums[i]) {
                set.add(stack.pop());
            }
            ans += set.size();
            stack.push(nums[i]);
        }
        Set<Integer> set = new HashSet<>();
        while (!stack.isEmpty()) {
            set.add(stack.pop());
        }
        set.remove(0);
        return ans + set.size();
    }
}