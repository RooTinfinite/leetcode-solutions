from typing import List
from functools import reduce

class Solution:
    @staticmethod
    def mod1(i: int, n: int) -> int:
        return i - (-(i >= n) & n)

    @staticmethod
    def decrypt(code: List[int], k: int) -> List[int]:
        n = len(code)
        if k < 0:
            s = sum(code[n + k:])
            code = [v << 16 for v in code]
            for i in range(n):
                v = code[i] >> 16
                code[i] += s
                j = Solution.mod1(n + k + i, n)
                s += v - (code[j] >> 16)
            code = [v & 0x3FFF for v in code]
        elif k > 0:
            s = sum(code[:k])
            code = [v << 16 for v in code]
            for i in range(n):
                v = code[i] >> 16
                j = Solution.mod1(i + k, n)
                s += (code[j] >> 16) - v
                code[i] += s
            code = [v & 0x3FFF for v in code]
        else:
            code = [0] * n
        return code

# Initialize faster I/O
import sys
input = sys.stdin.readline