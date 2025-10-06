class Solution {
    public int countArrays(int[] original, int[][] bounds) {
        int a1 = bounds[0][0];
        int a2 = bounds[0][1];
        int b1,b2,diff;
        for(int i = 1; i < original.length;i++){
            b1 = bounds[i][0];
            b2 = bounds[i][1];
            diff = original[i] - original[i-1];
            if(a1 + diff >= b1) b1 = a1 + diff;
            if(a2 + diff <= b2) b2 = a2 + diff;
            if(b1 > b2) return 0;
            a1 = b1;
            a2 = b2;
            
        }
        return a2 - a1 + 1;
    }
}