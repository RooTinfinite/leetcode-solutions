class Solution {
    public int climbStairs(int n, int[] costs) {
        int one = 0, two = costs[0] + 1, three = n > 1 ? costs[1] + Math.min(two + 1, 4) : two;
        for (int i = 3; i <= n; i++){
            int curr = costs[i-1] + Math.min(three + 1, Math.min(two + 4, one + 9));
            one = two;
            two = three;
            three = curr;
        }
        return three;
    }
}