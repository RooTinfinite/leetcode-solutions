

class Solution {

    public int almostPalindromic(String s) {
        int n = s.length();
        int max = 0;

        for (int i = 0; i < n; i++) {
            max = Math.max(max, expand(s, i, i));       // odd
            max = Math.max(max, expand(s, i, i + 1));   // even
        }

        return max;
    }

    private int expand(String s, int left, int right) {
        int n = s.length();
        int l = left;
        int r = right;

        while (l >= 0 && r < n) {

            if (s.charAt(l) == s.charAt(r)) {
                l--;
                r++;
            } else {
                // Try skipping either side ONCE
                int skipLeft = expandExact(s, l - 1, r);
                int skipRight = expandExact(s, l, r + 1);

                return Math.max(skipLeft, skipRight);
            }
        }

        // this is for the case like - zzabba
        // include the extra character 
        if(r >= n || l < 0){
            return  r - l > s.length() ? s.length() : r - l ;
        }

        // fully palindrome → deleting any one char works
        return r - l - 1;
    }

    private int expandExact(String s, int l, int r) {
        int n = s.length();

        while (l >= 0 && r < n && s.charAt(l) == s.charAt(r)) {
            l--;
            r++;
        }

        return r - l - 1;
    }
}