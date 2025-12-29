class Solution {
    public long minCost(String s, int[] cost) {
        long[] hash = new long[26];
        char[] c = s.toCharArray();
        long total_cost = 0 , max_cost = 0;
        for(int i = 0; i < cost.length; i++) {
            total_cost += cost[i];
            hash[c[i] - 'a'] += cost[i];
            if(hash[c[i] - 'a'] > max_cost) max_cost = hash[c[i] - 'a'];
        }
        return total_cost - max_cost;
    }
}