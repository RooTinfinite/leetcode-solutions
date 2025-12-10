public class Solution {
    public int Candy(int[] ratings) {
        int sum = 0;
        int length = ratings.Length;
        int[] left2right = Enumerable.Repeat(1, length).ToArray();
        int[] right2left = Enumerable.Repeat(1, length).ToArray();
        for (int i = 1; i < length; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left2right[i] = left2right[i - 1] + 1;
            }
        }

        for (int i = length - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right2left[i] = right2left[i + 1] + 1;
            }
        }

        for (int i = 0; i < length; i++) {
            sum += Math.Max(left2right[i], right2left[i]);
        }

        return sum;
    }
}