public class Solution {
    private int solve(int[] start1, int[] duration1, int[] start2,
                      int[] duration2) {
        int finish1 = int.MaxValue;
        for (int i = 0; i < start1.Length; i++) {
            finish1 = Math.Min(finish1, start1[i] + duration1[i]);
        }
        int finish2 = int.MaxValue;
        for (int i = 0; i < start2.Length; i++) {
            finish2 =
                Math.Min(finish2, Math.Max(start2[i], finish1) + duration2[i]);
        }
        return finish2;
    }

    public int EarliestFinishTime(int[] landStartTime, int[] landDuration,
                                  int[] waterStartTime, int[] waterDuration) {
        int land_water =
            solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int water_land =
            solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return Math.Min(land_water, water_land);
    }
}