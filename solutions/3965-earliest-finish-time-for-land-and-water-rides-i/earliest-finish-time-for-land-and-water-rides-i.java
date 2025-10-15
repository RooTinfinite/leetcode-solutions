class Solution {
    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        int res = Integer.MAX_VALUE;
        int n = landStartTime.length;
        int m = waterStartTime.length;

        // Try all combinations of one land and one water ride
        for (int i = 0; i < n; i++) {
            int a = landStartTime[i]; // start time of land ride
            int d = landDuration[i];  // duration of land ride

            for (int j = 0; j < m; j++) {
                int b = waterStartTime[j]; // start time of water ride
                int e = waterDuration[j];  // duration of water ride

                // Case 1: Land → Water
                int landEnd = a + d;
                int startWater = Math.max(landEnd, b); // wait if needed
                int finish1 = startWater + e;

                // Case 2: Water → Land
                int waterEnd = b + e;
                int startLand = Math.max(waterEnd, a); // wait if needed
                int finish2 = startLand + d;

                // Take the minimum finish time
                res = Math.min(res, Math.min(finish1, finish2));
            }
        }

        return res;
    }
}