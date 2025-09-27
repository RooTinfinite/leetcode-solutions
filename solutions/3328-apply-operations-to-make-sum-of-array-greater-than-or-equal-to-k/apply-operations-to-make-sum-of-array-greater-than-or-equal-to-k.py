class Solution:
    def minOperations(self, k: int) -> int:
        p = isqrt(k)
        q = (k+p-1)//p
        return p+q-2