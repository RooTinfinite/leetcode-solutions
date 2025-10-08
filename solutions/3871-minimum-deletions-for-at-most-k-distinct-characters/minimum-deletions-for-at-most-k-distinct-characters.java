class Solution {
    public int minDeletion(String s, int k) {
        var freq = new int[26];
        int distinct = 0;
        for (char ch : s.toCharArray()) {
            int idx = ch - 'a';
            if (freq[idx] == 0)
                distinct++;
            freq[ch - 'a']++;
        }
        if (k >= distinct)
            return 0;

        Arrays.sort(freq);
        int del = 0;
        for (int i = 0, j = 0; i < 26 && j < distinct - k; i++) {
            if (freq[i] != 0) {
                del += freq[i];
                j++;
            }
        }
        return del;
    }
}