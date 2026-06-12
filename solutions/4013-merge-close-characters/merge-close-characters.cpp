class Solution {
public:
    string mergeCharacters(string s, int k) {
        string result;
        result.reserve(s.size());

        int cnt[26] = {0}; 
        for (char c : s) {
            int idx = c - 'a';
            if (cnt[idx] > 0) // Merge = skip the character
                continue;

            // Add new character to the last k
            result.push_back(c);
            cnt[idx]++;

            if (result.size() > k) {  // If there were already k, remove the first one
                char drop = result[result.size() - k - 1];
                cnt[drop - 'a']--;
            }
        }

        return result;
    }
};