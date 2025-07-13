class Solution:
    def minPartitions(self, n: str) -> int:
        for i in range(9,0,-1):
            if str(i) in n:
                return i  