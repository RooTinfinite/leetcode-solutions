class Solution {
    public int beautifulNumbers(int l, int r) {
        /*sounds like that one digit dp problem by the name, also desc makes it seem like one
        from product of digits to be divisible by sum look at properties.
        
        Trivial cases:
            all 1 digit numbers are both their  product and sum so trivially beaut
            all number with a 0 in their digits have a product of 0, which is trivially divisible by everything and thus beaut
            
        beyond
        non-trivials:
        22, 36, 44, 63, 66, 88, 123, 132, 138, 145, 154, .....
        
        note: since prod and sum both commute, if one permutation of digiits is beaut, all are
        so really just looking at digit choices
        
        for all n digit numbers, can go through all possible 
            
        ehh screew these properties, I'll just try digit dp with the sum and product.
        
        */
        String leftStr = String.valueOf(l-1), rightStr = String.valueOf(r);
        Map<Integer, Integer>[][][] memo1 = new HashMap[leftStr.length()][2][leftStr.length() * 9 + 1];
        Map<Integer, Integer>[][][] memo2 = new HashMap[rightStr.length()][2][rightStr.length() * 9 + 1];
        for(int i = 0; i < memo1.length; i++) {
            for(int j = 0; j < memo1[i].length; j++) for(int k = 0; k < memo1[i][j].length; k++) memo1[i][j][k] = new HashMap<>();
        }
        for(int i = 0; i < memo2.length; i++) {
            for(int j = 0; j < memo2[i].length; j++) for(int k = 0; k < memo2[i][j].length; k++) memo2[i][j][k] = new HashMap<>();
        }
   
        return dp(rightStr, 0, true, 0, 1, memo2) - dp(leftStr, 0, true, 0, 1, memo1);
    }
    
    private int dp(String num, int index, boolean tight, int sum, int product, Map<Integer, Integer>[][][] memo) {
        if(index == num.length()) {
            return (sum > 0 && product % sum == 0) ? 1 : 0;
        }
        if(memo[index][tight ? 1 : 0][sum].containsKey(product)) {
            return memo[index][tight ? 1 : 0][sum].get(product);
        }
        int res = 0;
        for(int d = 0; d <= (tight ? num.charAt(index)-'0' : 9); d++) {
            int nextSum = d + sum;
            int nextProduct = nextSum == 0 ? 1 : product*d; //stay 1 if sum is 0, as no digits have been chosen so am in leading zeros
            res += dp(num, index + 1, tight && d == num.charAt(index)-'0', nextSum, nextProduct, memo);
        }
        
        memo[index][tight ? 1 : 0][sum].put(product, res);
        return res;
    }
}