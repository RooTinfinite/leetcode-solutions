function minDistance(word1: string, word2: string): number {
    let word1Length = word1.length;
    let word2Length = word2.length;
    if (word1Length == 0) {
        return word2Length;
    }
    if (word2Length == 0) {
        return word1Length;
    }
    let dp: number[][] = Array.from(Array(word1Length + 1), () =>
        Array(word2Length + 1).fill(0),
    );
    for (let word1Index = 1; word1Index <= word1Length; ++word1Index) {
        dp[word1Index][0] = word1Index;
    }
    for (let word2Index = 1; word2Index <= word2Length; ++word2Index) {
        dp[0][word2Index] = word2Index;
    }
    for (let word1Index = 1; word1Index <= word1Length; ++word1Index) {
        for (let word2Index = 1; word2Index <= word2Length; ++word2Index) {
            if (word2.charAt(word2Index - 1) == word1.charAt(word1Index - 1)) {
                dp[word1Index][word2Index] = dp[word1Index - 1][word2Index - 1];
            } else {
                dp[word1Index][word2Index] =
                    Math.min(
                        dp[word1Index - 1][word2Index],
                        dp[word1Index][word2Index - 1],
                        dp[word1Index - 1][word2Index - 1],
                    ) + 1;
            }
        }
    }
    return dp[word1Length][word2Length];
}