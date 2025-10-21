class Solution {
    public int maxXorSubsequences(int[] nums) {
        return maxXorSubset(nums);
    }

    public int maxXorSubset(int[] nums) {
        
        int [] basis = new int[32];
        for (int num: nums){
            int x = num ;
            while(x != 0){
                
                int highestBitOn = 31 - Integer.numberOfLeadingZeros(x);
                if (basis[highestBitOn] == 0){
                    basis[highestBitOn] = x;
                } else {
                    x ^= basis[highestBitOn];
                }
            }
        }

        // System.out.println(Arrays.toString(basis));
        int max = 0 ;
        for(int i =31; i >=0; i--){
            if (max < (max ^ basis[i])){
                max = max ^ basis[i];
            }
        }
        
        return max;
    }
}