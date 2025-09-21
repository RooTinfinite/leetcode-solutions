from typing import List

class Solution:
    def closestTarget(self, W: List[str], T: str, s: int) -> int:
        a, n = float('inf'), len(W)
        for i in range(n):
            if W[i] == T:
                d = abs(i - s)
                a = min(a, d, n - d)
        return -1 if a == float('inf') else a