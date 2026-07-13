class Solution {
    public int minOperations(int[] nums, int k) {
        int min = Integer.MAX_VALUE;
        for(int i = 0 ; i < k ; i++){
            for(int j = 0 ; j < k ; j++){
                if(i == j)
                    continue;
                int x = i,y = j,cnt = 0;
                for(int p = 0 ; p < nums.length ; p++){
                    if(p % 2 == 0){
                        cnt += Math.min((nums[p] % k - x + k ) % k,(x - nums[p] % k + k) % k);
                    }
                    else{
                        cnt += Math.min((nums[p] % k - y + k ) % k,(y - nums[p] % k + k) % k);
                    }
                }
                min = Math.min(min,cnt);
            }
        }
        return  min;
    }
}