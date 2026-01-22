public class Solution {
    public int MinimumPairRemoval(int[] nums) {
        var count = 0;
        var list = nums.ToList();

        while (list.Count > 1) {
            var isAscending = true;
            var minSum = int.MaxValue;
            var targetIndex = -1;

            for (var i = 0; i < list.Count - 1; i++) {
                var sum = list[i] + list[i + 1];

                if (list[i] > list[i + 1]) {
                    isAscending = false;
                }

                if (sum < minSum) {
                    minSum = sum;
                    targetIndex = i;
                }
            }

            if (isAscending) {
                break;
            }

            count++;
            list[targetIndex] = minSum;
            list.RemoveAt(targetIndex + 1);
        }

        return count;
    }
}