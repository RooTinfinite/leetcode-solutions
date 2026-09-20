class Solution {
    static List<Integer> odd = new ArrayList<>(); 
    static List<Integer> even = new ArrayList<>(); 
    static int inf = (int) 1e9; 

    private static long mirror(int x, boolean flag) {
        // 1 -> odd: 1 , 12: 121 , 1345 -> 1345431 
        // 1 -> even: 11, 1221 
        long cur = x; 
        if(flag) x /= 10; // in case of odd middle nu will not mirror 
        
        while(x > 0) {
            cur = cur * 10 + x % 10; 
            x/= 10; 
        }
        return cur; 
    }
    private static void generatePalindroms() {
        for(int i = 1; i <= 99_999; i++) {
            long x = mirror(i, true); // odd length
            
            if(x <= inf) {
                if(x % 2 == 0) even.add((int)x); 
                else odd.add((int)x); 
            }
            long y = mirror(i, false); // even length

            if(y <= inf) {
                if(y % 2 == 0) even.add((int)y); 
                else odd.add((int)y); 
            } 
        }

        Collections.sort(odd); 
        Collections.sort(even); 
    }

    static {
        generatePalindroms();
    }
    public long minOperations(int[] nums) {
        // let's focus on generating all palindrome's first 
        // they will be small as only first 5 positions can vary... rest will be same 
        // so roughly 1e5 only then we can apply bs on it. 
        long cnt = 0; 
        for(int x: nums) {
            long req = Long.MAX_VALUE; 

            List<Integer> arr = x % 2 == 0 ? even : odd; 
            int pos = lowerBound(arr, x); 
                
            if(pos > 0) {
                // we have a valid prev 
                req = Math.min(req, (x - arr.get(pos - 1)) / 2); 
            }
            if(pos < arr.size()) {
                // we have vlaid next 
                req = Math.min(req, (arr.get(pos) - x)/ 2); 
            }
            cnt += req; 
        }

        return cnt; 
    }

    private int lowerBound(List<Integer> nums, int target) {
        int lo = 0, hi = nums.size() - 1; 
        int ans = nums.size(); 
        while(lo <= hi) {
            int mid = (lo + hi) >> 1; 
            if(nums.get(mid) >= target) {
                ans = mid; 
                hi = mid - 1; 
            } else {
                lo = mid + 1; 
            }
        }
        return ans; 
    }
}