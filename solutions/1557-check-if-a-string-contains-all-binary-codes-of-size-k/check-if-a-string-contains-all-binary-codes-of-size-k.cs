public class Solution {
    public bool HasAllCodes(string s, int k) {
        int req = 1 << k;
        bool[] seen = new bool[req];
        int mask = req - 1;
        int hash = 0;

        for (int i = 0; i < s.Length; ++i) {
            hash = ((hash << 1) & mask) | (s[i] & 1);

            if (i >= k - 1 && !seen[hash]) {
                seen[hash] = true;
                req--;
                if (req == 0) return true;
            }
        }

        return false;
    }
}