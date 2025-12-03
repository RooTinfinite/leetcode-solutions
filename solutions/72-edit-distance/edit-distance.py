class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        word1Length = len(word1)
        word2Length = len(word2)
        if word1Length == 0:
            return word2Length
        if word2Length == 0:
            return word1Length
        dp = [
            [0 for _ in range(word2Length + 1)] for _ in range(word1Length + 1)
        ]
        for word1Index in range(1, word1Length + 1):
            dp[word1Index][0] = word1Index
        for word2Index in range(1, word2Length + 1):
            dp[0][word2Index] = word2Index
        for word1Index in range(1, word1Length + 1):
            for word2Index in range(1, word2Length + 1):
                if word2[word2Index - 1] == word1[word1Index - 1]:
                    dp[word1Index][word2Index] = dp[word1Index - 1][
                        word2Index - 1
                    ]
                else:
                    dp[word1Index][word2Index] = (
                        min(
                            dp[word1Index - 1][word2Index],
                            dp[word1Index][word2Index - 1],
                            dp[word1Index - 1][word2Index - 1],
                        )
                        + 1
                    )
        return dp[word1Length][word2Length]