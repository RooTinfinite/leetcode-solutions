class Solution {
    int dist(char a, char b) {
        int x = Math.abs((a - '0') - (b - '0'));
        return Math.min(x, 10 - x);
    }

    public int minRotations(String s) {
        int total = 0;
        char last = '0';

        for (char c : s.toCharArray()) {
            total += dist(last, c);
            last = c;
        }

        return total;
    }
}