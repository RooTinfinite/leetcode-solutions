class Solution {
    public boolean validDigit(int n, int x) {
        String str = String.valueOf(n);
        char ch = (char) (x + '0');
        if(str.charAt(0) != ch && str.indexOf(ch) != -1)
            return true;
        return false;
    }
}