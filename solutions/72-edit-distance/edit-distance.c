int min(int a, int b, int c) {
    int temp = a < b ? a : b;
    return temp < c ? temp : c;
}
int minDistance(char* word1, char* word2) {
    // The sizes of the words
    int word1Length = strlen(word1);
    int word2Length = strlen(word2);
    // If word1 is empty, the answer is the size of word2
    if (word1Length == 0) {
        return word2Length;
    }
    // If word2 is empty, the answer is the size of word1
    if (word2Length == 0) {
        return word1Length;
    }
    int dp[word1Length + 1][word2Length + 1];
    dp[0][0] = 0;
    for (int word1Index = 1; word1Index <= word1Length; word1Index++) {
        dp[word1Index][0] = word1Index;
    }
    for (int word2Index = 1; word2Index <= word2Length; word2Index++) {
        dp[0][word2Index] = word2Index;
    }
    for (int word1Index = 1; word1Index <= word1Length; word1Index++) {
        for (int word2Index = 1; word2Index <= word2Length; word2Index++) {
            if (word2[word2Index - 1] == word1[word1Index - 1]) {
                dp[word1Index][word2Index] = dp[word1Index - 1][word2Index - 1];
            } else {
                dp[word1Index][word2Index] =
                    min(dp[word1Index - 1][word2Index],
                        dp[word1Index][word2Index - 1],
                        dp[word1Index - 1][word2Index - 1]) +
                    1;
            }
        }
    }
    return dp[word1Length][word2Length];
}