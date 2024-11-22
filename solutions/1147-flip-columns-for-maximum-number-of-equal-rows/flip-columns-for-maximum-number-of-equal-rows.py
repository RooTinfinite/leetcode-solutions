class Solution:
    def maxEqualRowsAfterFlips(self, mat: List[List[int]]) -> int:
        pat_freq = Counter()
        
        for r in mat:
            pattern = tuple(r) if r[0] == 0 else tuple(bit ^ 1 for bit in r)
            pat_freq[pattern] += 1
            
        return max(pat_freq.values())