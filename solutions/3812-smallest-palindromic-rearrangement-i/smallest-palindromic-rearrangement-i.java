class Solution {
    public String smallestPalindrome(String s) {
        if(s.length() == 1) {
            return s;
        }
        int n = s.length();
        String half = s.substring(0, n / 2);
        char[] arr = half.toCharArray();
        Arrays.sort(arr);
        String sortedHalf = new String(arr);
        String reversedHalf = new StringBuilder(sortedHalf).reverse().toString();
        if(n % 2 == 0) {
            return sortedHalf + reversedHalf;
        } 
        else {
            char mid = s.charAt(n / 2);
            return sortedHalf + mid + reversedHalf;
        }
    }
}