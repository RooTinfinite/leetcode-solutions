class Solution {

    public long minimumCost(String s, String t, int flipCost, int swapCost, int crossCost) {

        char[] S = s.toCharArray() ;
        char[] T = t.toCharArray() ;

        int n = S.length ;

        int e01 = 0 ;
        int e10 = 0 ;

        for(int i = 0 ; i < n ; i ++)
        {
            if(S[i] == '0' && T[i] == '1') e01 ++ ;
            else if(S[i] == '1' && T[i] == '0') e10 ++ ;
        }

        long c1 = 1L * (e01 + e10) * flipCost ;

        int min = Math.min(e01, e10) ;
        int max = Math.max(e01, e10) ;

        long swap = 1L * min * swapCost ;
        long remaining = max - min ;

        long c2 = swap + remaining * flipCost ;

        long c3 = swap
                + (remaining / 2) * (crossCost + swapCost)
                + (remaining % 2) * flipCost ;

        return Math.min(c1, Math.min(c2, c3)) ;
    }
}