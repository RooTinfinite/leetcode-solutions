class Solution:
    def minDeletion(self, s: str, k: int) -> int:
        freq = [0 for _ in range(26)]
        dis = 0
        for ch in s:
            idx = ord(ch) - ord('a')
            if freq[idx] == 0:
                dis += 1
            freq[idx] += 1

        if k >= dis:
            return 0

        delete = 0
        freq.sort()
        
        i, j = 0, 0
        while i < 26 and j < dis - k:
            if freq[i]:
                delete += freq[i]
                j += 1
            i += 1
        return delete