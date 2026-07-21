class Solution {
    public long maximumSum(int[] nums, int m, int l, int r) {

        int n = nums.length ;

        long[] preSum = new long[n + 1] ;
        for(int i = 0 ; i < n ; i ++)
        {
            preSum[i + 1] = preSum[i] + nums[i] ;
        }

        long NEG = -(long) 4e18 ;

        long[] prev = new long[n + 1] ;

        long ans = NEG ;

        for(int j = 1 ; j <= m ; j ++)
        {
            long[] curr = new long[n + 1] ;
            for(int i = 0 ; i <= n ; i ++)
            {
                curr[i] = NEG ;
            }

            int[] dq = new int[n + 1] ;
            int head = 0 ;
            int tail = 0 ;

            for(int i = 1 ; i <= n ; i ++)
            {
                curr[i] = curr[i - 1] ;

                int add = i - l ; 

                if(add >= 0 && prev[add] != NEG)
                {
                    long val = prev[add] - preSum[add] ;

                    while(head < tail)
                    {
                        int last = dq[tail - 1] ;

                        long lastVal = prev[last] - preSum[last] ;

                        if(lastVal >= val) break ;

                        tail -- ;
                    }

                    dq[tail ++] = add ;
                }

                while(head < tail && dq[head] < i - r) head ++ ;

                if(head < tail)
                {
                    int k = dq[head] ;

                    curr[i] = Math.max(curr[i], preSum[i] + prev[k] - preSum[k]) ;
                }
            }

            for(int i = 0 ; i <= n ; i ++)
            {
                ans = Math.max(ans, curr[i]) ;
            }

            prev = curr ;
        }

        return ans ;
        
    }
}