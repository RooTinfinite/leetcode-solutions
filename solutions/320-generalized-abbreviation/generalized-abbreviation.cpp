class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        int N = word.size();
        vector<string> abbreviations;

        for (int mask = 0; mask < (1 << N); mask++) {
            string currWord;
            int abbreviatedCount = 0;

            for (int index = 0; index < N; index++) {
                // If the bit at position index is 1, increment the abbreviated
                // substring.
                if (mask & (1 << index)) {
                    abbreviatedCount++;
                } else {
                    // Append the last substring and then the current character.
                    currWord +=
                        (abbreviatedCount == 0 ? ""
                                               : to_string(abbreviatedCount)) +
                        word[index];
                    abbreviatedCount = 0;
                }
            }

            currWord +=
                abbreviatedCount == 0 ? "" : to_string(abbreviatedCount);
            abbreviations.push_back(currWord);
        }

        return abbreviations;
    }
};