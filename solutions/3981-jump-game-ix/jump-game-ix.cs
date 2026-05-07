public class Solution {
    public int[] MaxValue(int[] nums) {
        int n = nums.Length;
        int[] ans = new int[n];

        List<(int Value, int Left, int Right)> stack = new();

        for (int i = 0; i < n; i++) {
            var curr = (Value: nums[i], Left: i, Right: i);

            while (stack.Count > 0 && stack[^1].Value > nums[i]) {
                var top = stack[^1];
                stack.RemoveAt(stack.Count - 1);
                curr = (Math.Max(curr.Value, top.Value), top.Left, curr.Right);
            }

            stack.Add(curr);
        }

        for (int i = 0; i < stack.Count; i++) {
            for (int j = stack[i].Left; j <= stack[i].Right; j++) {
                ans[j] = stack[i].Value;
            }
        }

        return ans;
    }
}