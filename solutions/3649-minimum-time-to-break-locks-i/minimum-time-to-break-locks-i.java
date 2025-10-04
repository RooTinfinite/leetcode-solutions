class Solution {
    public int findMinimumTime(List<Integer> strength, int k) {
        int m = strength.size();
        //Collections.sort(strength);
        Integer[] memo = new Integer[1 << m];
        return helper((1 << m) - 1, 0, m, strength, memo, k);
    }
    private int helper(int bitmask, int index, int m, List<Integer> strength, Integer[] memo, int k){
        if(bitmask == 0){
            return 0;
        }
        if(memo[bitmask] != null){
            return memo[bitmask];
        }
        int currentx = 1 + k * index;
        int mintime = Integer.MAX_VALUE;
        for(int i = 0; i < m; i++){
            if((bitmask & (1 << i)) != 0){
                int currentstrength = strength.get(i);
                int time = (currentstrength + currentx - 1) / currentx;
                int currentbitmask = bitmask ^ (1 << i);
                int totaltime = time + helper(currentbitmask, index + 1, m, strength, memo, k);
                mintime = Math.min(mintime, totaltime);
            }
            if(mintime == 0){
                break;
            }
        }
        memo[bitmask] = mintime;
        return mintime;
    }
}