class Solution {
    public int mirrorFrequency(String s) {
        int[] f1 = new int[10];
        int[] f2 = new int[26];

        for (char ch : s.toCharArray()) {
            if (ch >= '0' && ch <= '9') {
                f1[ch - '0']++;
            } else {
                f2[ch - 'a']++;
            }
        }

        int ans = 0;

        for (int i = 0; i < 5; i++) {
            ans += Math.abs(f1[i] - f1[9 - i]);
        }

        for (int i = 0; i < 13; i++) {
            ans += Math.abs(f2[i] - f2[25 - i]);
        }

        return ans;
    }
}