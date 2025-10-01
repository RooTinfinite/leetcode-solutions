class Solution {
    public long findGcd(long a, long b){
        while (b != 0){
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    public long findLcm(long a, long b){ 
        return (a * b) / findGcd(a,b);
    }
    public long maxScore(int[] nums) {
        int n = nums.length;
        if (n == 0) {
            return 0;
        }
        if (n == 1){
            return nums[0]*nums[0];
        }
        long[] preGcd = new long[n];
        long[] sufGcd = new long[n];
        long[] preLcm = new long[n];
        long[] sufLcm = new long[n];

        preGcd[0] = nums[0];
        sufGcd[n-1] = nums[n-1];
        preLcm[0] = nums[0];
        sufLcm[n-1] = nums[n-1];

        for (int i = 1; i < n; i++){
            preGcd[i] = findGcd(preGcd[i-1], nums[i]);
            
            preLcm[i] = findLcm(preLcm[i-1], nums[i]);
        }

        for (int i = n - 2; i >= 0; i--){
            sufGcd[i] = findGcd(sufGcd[i+1], nums[i]);
            sufLcm[i] = findLcm(sufLcm[i+1], nums[i]);
            //system.out.println("suf gcd and sf lcm is :" +sufGcd[1] + " "+ sufLcm[1]);
        }

        long maxScore = preGcd[n-1] * preLcm[n-1];

        for (int skip = 0; skip < n;skip++){
            long currScore;
            if (skip == 0){
                currScore = sufGcd[1] * sufLcm[1];
                //System.out.println(sufGcd[1] + " "+ sufLcm[1]);
                maxScore = Math.max(maxScore, currScore);
                //System.out.println("currScore is :" + currScore);
                continue;
            }
            if (skip == n - 1){
                currScore = preGcd[n-2] * preLcm[n-2];
                maxScore = Math.max(maxScore, currScore);
                continue;
            }
            long gcd = findGcd(preGcd[skip-1], sufGcd[skip+1]);
            long lcm = findLcm(preLcm[skip-1], sufLcm[skip+1]);
            currScore =  gcd * lcm; 
            maxScore = Math.max(maxScore, currScore);
        }
        return maxScore;
    }
}