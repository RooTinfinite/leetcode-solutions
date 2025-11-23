public class Solution {
    public int MaxSumDivThree(int[] nums) {
        // Use v[0], v[1], v[2] to represent a, b, c respectively.
        IList<int>[] v = new IList<int>[3];
        for (int i = 0; i < 3; ++i) {
            v[i] = new List<int>();
        }
        foreach (int num in nums) {
            v[num % 3].Add(num);
        }
        ((List<int>)v[1]).Sort((a, b) => b - a);
        ((List<int>)v[2]).Sort((a, b) => b - a);

        int tot = nums.Sum();
        int remove = int.MaxValue;

        if (tot % 3 == 0) {
            remove = 0;
        } else if (tot % 3 == 1) {
            if (v[1].Count >= 1) {
                remove = Math.Min(remove, v[1][v[1].Count - 1]);
            }
            if (v[2].Count >= 2) {
                remove = Math.Min(remove,
                                  v[2][v[2].Count - 2] + v[2][v[2].Count - 1]);
            }
        } else {
            if (v[1].Count >= 2) {
                remove = Math.Min(remove,
                                  v[1][v[1].Count - 2] + v[1][v[1].Count - 1]);
            }
            if (v[2].Count >= 1) {
                remove = Math.Min(remove, v[2][v[2].Count - 1]);
            }
        }

        return tot - remove;
    }
}