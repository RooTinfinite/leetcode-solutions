class Solution:
    def maxEqualRowsAfterFlips(self, mat: List[List[int]]) -> int:
        freq = {}
        n = len(mat[0])
        
        for row in mat:
            pattern = []
            first_bit = row[0]
            
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
                
            pattern = tuple(pattern)
            freq[pattern] = freq.get(pattern, 0) + 1
            
        return max(freq.values())