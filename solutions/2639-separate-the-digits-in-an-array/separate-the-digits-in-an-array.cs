class Solution {
    public int[] SeparateDigits(int[] nums) {
        List<int> res = new List<int>();
        for (int i = nums.Length - 1; i >= 0; i--) {
            int x = nums[i];
            while (x > 0) {
                res.Add(x % 10);
                x /= 10;
            }
        }
        res.Reverse();
        return res.ToArray();
    }
}