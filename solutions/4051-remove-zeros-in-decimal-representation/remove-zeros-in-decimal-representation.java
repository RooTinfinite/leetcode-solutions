class Solution {
    public long removeZeros(long n) {             
        String result = (n + "").replace("0", ""); 
        return Long.parseLong(result);     
    }
}