class Solution {
    public int maxTotalReward(int[] rewardValues) {
        int n = rewardValues.length;
        Arrays.sort(rewardValues);
        int maxPossibleScove = rewardValues[n - 1] * 2;
        
        boolean[] preDP = new boolean[maxPossibleScove + 1];
        boolean[] curDP = new boolean[maxPossibleScove + 1];
        preDP[0] = true;
        for(int i = 0; i < rewardValues.length; i++) {
            for(int j = 0; j < rewardValues[i]; j++) {
                curDP[j + rewardValues[i]] = curDP[j + rewardValues[i]] | preDP[j];
            }
            for(int j = 0; j < curDP.length; j++) {
                preDP[j] = preDP[j] | curDP[j];
                curDP[j] = false;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < preDP.length; i++) {
            if(preDP[i]) {
                ans = i;
            }
        }
        return ans;
    }
}