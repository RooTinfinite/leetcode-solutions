class Solution:
    def smallestNumber(self, n: int, t: int) -> int:

        for i in range(n, n + 10):
            if reduce(mul, map(int,str(i))) %t == 0: return i