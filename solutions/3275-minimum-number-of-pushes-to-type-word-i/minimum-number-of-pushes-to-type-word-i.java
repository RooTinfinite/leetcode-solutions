class Solution {
    public int minimumPushes(String word) {
        int n = word.length();
        int a = 0, b = n;

        if (b > 8) a = a + 8;
        else return (a + b);

        if (b > 16) a = a + 8 * 2;
        else return (a + (b - 8) * 2);

        if (b > 24) a = a + 8 * 3;
        else return (a + (b - 16) * 3);

        if (b == 25) a = a + 4;

        if (b == 26) a = a + 8;

        return a;
    }
}