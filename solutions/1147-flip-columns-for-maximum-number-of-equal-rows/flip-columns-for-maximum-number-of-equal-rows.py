class Solution:
    def maxEqualRowsAfterFlips(self, mat: List[List[int]]) -> int:
        freq = Counter()
        
        for r in mat:
            pat = tuple(r) if r[0] == 0 else tuple(bit ^ 1 for bit in r)
            freq[pat] += 1
            
        return max(freq.values())