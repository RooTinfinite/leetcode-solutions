class Solution:
    def maxEqualRowsAfterFlips(self, mat: List[List[int]]) -> int:
        pattern_map = {}
        
        for row in mat:
            pattern = ''.join(map(str, row))
            flipped = ''.join('1' if x == '0' else '0' for x in pattern)
            
            key = min(pattern, flipped)
            pattern_map[key] = pattern_map.get(key, 0) + 1
        
        return max(pattern_map.values())