
import java.math.BigInteger;
class Solution {
    // int count = 0;
    // public void helper(int[] nums,int idx, boolean[] freq, long k){
    //     if(idx == nums.length){
    //         count++;
    //         return ;
    //     }

    //     for(int i=1; i<freq.length; i++){
    //         if (!freq[i] && (idx == 0 || (i + nums[idx - 1]) % 2 == 1)){
    //             freq[i] = true;
    //             nums[idx] = i;
    //             helper(nums, idx+1, freq, k);
    //             if(count == k)
    //                 return;
    //             freq[i] = false;
    //             nums[idx] = 0;
    //         }
    //     }
    // }






    private HashMap<Integer, BigInteger> factMemo = new HashMap<>();

    public BigInteger fact(int n) {
        if (n <= 1) return BigInteger.ONE;
        if (factMemo.containsKey(n)) return factMemo.get(n);
        BigInteger res = BigInteger.valueOf(n).multiply(fact(n - 1));
        factMemo.put(n, res);
        return res;
    }

    public int[] permute(int n, long k) {
        int[] res = new int[n];
        int idx = 0;
        boolean[] available = new boolean[n + 1];
        int even = n / 2, odd = (n + 1) / 2;
        int prev = 0, count = n;
        
        while (count > 0) {
            int num = 1;
            boolean selected = false;
            
            while (!selected && num <= n) {
                if (!available[num] && (prev == 0 || (prev + num) % 2 == 1) && (num % 2 == 0 ? even >= odd : even <= odd)) {
                    BigInteger total = fact(count / 2).multiply(fact((count - 1) / 2));
                    
                    if (BigInteger.valueOf(k).compareTo(total) > 0) {
                        k -= total.longValue();
                    } else {
                        prev = num;
                        available[num] = true;
                        selected = true;
                        if (num % 2 == 0) even--;
                        else odd--;
                        res[idx++] = num;
                    }
                }
                num++;
            }
            
            if (!selected) return new int[]{};
            count--;
        }
    
        return res;
    }



}