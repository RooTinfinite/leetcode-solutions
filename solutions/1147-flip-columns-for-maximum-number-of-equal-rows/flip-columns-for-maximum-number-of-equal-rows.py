class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        patterns = {}
        for row in matrix:
            pattern = tuple(row) if row[0] == 0 else tuple(1-x for x in row)
            patterns[pattern] = patterns.get(pattern, 0) + 1
        return max(patterns.values())