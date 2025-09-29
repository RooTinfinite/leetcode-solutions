class Solution {
    public long countCompleteDayPairs(int[] hours) {
        long ans = 0;
        int[] count = new int[24];
        
        for (int i = 0; i < hours.length; i++) {
            ans += count[(24 - hours[i] % 24) % 24];
            count[hours[i] % 24]++;
        }
        
        return ans;
    }
}