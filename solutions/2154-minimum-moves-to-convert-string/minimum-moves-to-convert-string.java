class Solution {
    public int minimumMoves(String s) {
        int m = 0;
        int i = 0;
        while(i < s.length()){
            if(s.charAt(i) == 'X'){
                m++;
                i += 3;
            } else {
                i++;
            }
        }
        return m;
    }
}