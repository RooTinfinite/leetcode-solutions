public class Solution {
    public IList<int> TargetIndices(int[] nums, int target) {
        int cnt1 = 0;  // Number of elements less than target
        int cnt2 = 0;  // Number of elements equal to target

        foreach (int num in nums) {
            if (num < target) {
                cnt1++;
            } else if (num == target) {
                cnt2++;
            }
        }

        List<int> res = new List<int>();
        for (int i = cnt1; i < cnt1 + cnt2; i++) {
            res.Add(i);
        }
        return res;
    }
}