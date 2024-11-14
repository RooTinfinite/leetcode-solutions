class Solution {
public:
    int partitionString(string s) {
        int last_pos[26] = {}, partitions = 0, last_end = 0;
        for (int i = 0; i < s.length(); i++) {
            if (last_pos[s[i] - 'a'] >= last_end) {
                partitions++;
                last_end = i + 1;
            }
            last_pos[s[i] - 'a'] = i + 1;
        }
        return partitions;
    }
};