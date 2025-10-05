class Solution {
    public long maxWeight(int[] pizzas) {
        int n = pizzas.length;
        int days = n / 4;
        long wt = 0;

        int odd = (days + 1) / 2;   // odd days
        int even = days - odd;      // even days

        Arrays.sort(pizzas);
        int idx = n - 1;

        // Odd days → pick largest (Z)
        while (odd-- > 0) {
            wt += pizzas[idx--];
        }

        // Even days → pick second largest (Y)
        idx--; // skip Z
        while (even-- > 0) {
            wt += pizzas[idx];
            idx -= 2; // skip W and X
        }

        return wt;
    }
}