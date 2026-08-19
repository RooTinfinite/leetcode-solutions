public class Solution {
    public int MaxNumberOfFamilies(int n, int[][] reservedSeats) {
        int left = 0b11110000;
        int middle = 0b11000011;
        int right = 0b00001111;

        Dictionary<int, int> occupied = new Dictionary<int, int>();
        foreach (int[] seat in reservedSeats) {
            if (seat[1] >= 2 && seat[1] <= 9) {
                int row = seat[0];
                if (!occupied.ContainsKey(row)) {
                    occupied[row] = 0;
                }
                occupied[row] |= (1 << (seat[1] - 2));
            }
        }

        int ans = (n - occupied.Count) * 2;
        foreach (var kvp in occupied) {
            int bitmask = kvp.Value;
            if ((bitmask | left) == left || (bitmask | middle) == middle ||
                (bitmask | right) == right) {
                ans++;
            }
        }
        return ans;
    }
}