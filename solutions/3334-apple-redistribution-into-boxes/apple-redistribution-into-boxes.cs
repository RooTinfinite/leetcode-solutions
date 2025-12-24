public class Solution {
    public int MinimumBoxes(int[] apple, int[] capacity) {
        int sum = apple.Sum();
        Array.Sort(capacity);
        Array.Reverse(capacity);

        int need = 0;
        while (sum > 0) {
            sum -= capacity[need];
            need += 1;
        }

        return need;
    }
}