class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        pattern_frequency = {}
        for row in matrix:
            pattern = tuple(x == row[0] for x in row)
            pattern_frequency[pattern] = pattern_frequency.get(pattern, 0) + 1
        return max(pattern_frequency.values())