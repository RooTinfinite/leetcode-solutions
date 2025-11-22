class Solution {
    public int minimumFlips(int n) {
        String s = Long.toBinaryString(n);
        int len = s.length();
        int count = 0;
        for(int i = 0; i < len; i++) {
            if(s.charAt(i) != s.charAt(len - 1 - i)) count++;
        }
        return count;
    }
}