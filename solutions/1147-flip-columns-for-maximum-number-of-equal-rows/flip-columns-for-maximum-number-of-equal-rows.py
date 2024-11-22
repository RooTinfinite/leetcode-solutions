class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        pattern_frequency = Counter()
        
        for current_row in matrix:
            canonical_pattern = tuple(current_row) if current_row[0] == 0 else tuple(bit ^ 1 for bit in current_row)
            pattern_frequency[canonical_pattern] += 1
            
        return max(pattern_frequency.values())