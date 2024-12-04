class Solution:
    def canMakeSubsequence(self, A: str, B: str) -> bool:
        bi = 0
        for a in A:
            if bi < len(B) and (ord(B[bi]) - ord(a)) % 26 < 2: bi += 1
        return bi == len(B)