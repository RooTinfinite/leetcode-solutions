public class Solution {
    public int MajorityElement(int[] nums) {
        int count = 0;
        int? candidate = null;

        foreach (int num in nums) {
            if (count == 0) {
                candidate = num;
            }

            count += (num == candidate) ? 1 : -1;
        }

        return candidate.Value;
    }
}