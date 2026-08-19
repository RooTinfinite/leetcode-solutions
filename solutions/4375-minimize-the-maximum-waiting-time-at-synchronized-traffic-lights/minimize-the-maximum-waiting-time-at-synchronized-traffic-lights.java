class Solution {
    public int minPenalty(
        int period,
        int[] lights,
        int[] arrivalTime
    ) {
        int maxAns = Integer.MIN_VALUE;
        int maxLight = Integer.MIN_VALUE;

        for (int light : lights) {
            maxLight = Math.max(maxLight, light);
        }

        for (int at : arrivalTime) {
            int currentTime = at % period;

            if (currentTime >= maxLight) {
                maxAns = Math.max(
                    maxAns,
                    period - currentTime
                );
            }
        }

        return maxAns == Integer.MIN_VALUE ? 0 : maxAns;
    }
}