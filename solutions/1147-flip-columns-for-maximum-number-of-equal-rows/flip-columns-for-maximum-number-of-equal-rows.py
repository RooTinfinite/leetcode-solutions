class Solution:
    def maxEqualRowsAfterFlips(self, mat: List[List[int]]) -> int:
        res = 0
        n = len(mat[0])
        freq = {}
        
        for row in mat:
            first_bit = row[0]
            pattern = bytearray()
            
            i = 0
            while i + 7 < n:
                packed = 0
                for j in range(8):
                    if row[i + j] != first_bit:
                        packed |= (1 << j)
                pattern.append(packed)
                i += 8
            
            if i < n:
                packed = 0
                for j in range(n - i):
                    if row[i + j] != first_bit:
                        packed |= (1 << j)
                pattern.append(packed)
            
            pattern_bytes = bytes(pattern)
            freq[pattern_bytes] = freq.get(pattern_bytes, 0) + 1
            res = max(res, freq[pattern_bytes])
            
        return res