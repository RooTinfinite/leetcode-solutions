class Solution {
    public double minPrice(int[] prices, int[] discounts) {
        Arrays.sort(prices);
        Arrays.sort(discounts);

        int p1 = prices.length - 1;
        int p2 = discounts.length - 1;

        double sum = 0;

        while(p1 >= 0 && p2 >= 0){
            sum += prices[p1] *
                   (100.0 - discounts[p2]) / 100.0;

            p1--;
            p2--;
        }

        while(p1 >= 0){
            sum += prices[p1--];
        }

        return sum;
    }
}