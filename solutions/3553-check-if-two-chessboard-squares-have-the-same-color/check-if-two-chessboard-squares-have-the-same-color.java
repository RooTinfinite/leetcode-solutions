class Solution {
    public boolean checkTwoChessboards(String coordinate1, String coordinate2) {
        int val1 = (coordinate1.charAt(0) - 'a' + 1 + coordinate1.charAt(1) - '0');
        int val2 = (coordinate2.charAt(0) - 'a' + 1 + coordinate2.charAt(1) - '0');
        return (val1 % 2) == (val2 % 2);
    }
}