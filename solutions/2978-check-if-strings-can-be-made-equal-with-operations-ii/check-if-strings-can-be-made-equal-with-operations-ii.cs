public class Solution {
    public bool CheckStrings(string s1, string s2) {
        if (s1.Length != s2.Length) {
            return false;
        }

        int[] counts = new int[256];

        for (int i = 0; i < s1.Length; i++) {
            int offset = (i & 1) << 7;
            counts[offset + s1[i]]++;
            counts[offset + s2[i]]--;
        }

        foreach (int count in counts) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
}