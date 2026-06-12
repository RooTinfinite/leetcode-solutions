class Solution {
    public String mergeCharacters(String s, int k) {
        StringBuilder result = new StringBuilder();
        result.ensureCapacity(s.length());

        int[] cnt = new int[26];
        for (int t = 0; t < s.length(); t++) {
            char c = s.charAt(t);
            int idx = c - 'a';
            if (cnt[idx] > 0) // Merge = skip the character
                continue;

            // Add new character to the last k
            result.append(c);
            cnt[idx]++;

            if (result.length() > k) {  // If there were already k, remove the first one
                char drop = result.charAt(result.length() - k - 1);
                cnt[drop - 'a']--;
            }
        }

        return result.toString();
    }
}