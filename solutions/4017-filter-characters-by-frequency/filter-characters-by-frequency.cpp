class Solution {
public:
    string filterCharacters(string s, int k) {
        unordered_map<char, int> counter;

        // 1. Make frequency counter of s
        for (char letter : s) {
            counter[letter]++;
        }

        // 2. Construct the result
        string result;
        result.reserve(s.size()); // reserve memory for efficiency

        for (char letter : s) {
            if (counter[letter] < k) {
                result.push_back(letter);
            }
        }

        return result;
    }
};