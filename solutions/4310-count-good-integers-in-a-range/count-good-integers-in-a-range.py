class Solution:
    def __init__(self):
        self.dp = []

    def get(self, s: str, n: int, i: int, prev: int, small: bool, k: int) -> int:
        if i == n:
            return 1
        
        small_idx = 1 if small else 0
        if self.dp[i][prev][small_idx] != -1:
            return self.dp[i][prev][small_idx]
        
        res = 0
        start = max(0, prev - k)
        end = min(9, prev + k)
        if small == False:
            end = min(end, int(s[i]))
            
        for j in range(start, end + 1):
            res += self.get(s, n, i + 1, j, small or (j < int(s[i])), k)
            
        self.dp[i][prev][small_idx] = res
        return res

    def f(self, num: int, k: int) -> int:
        self.dp = [[[-1 for _ in range(2)] for _ in range(10)] for _ in range(16)]

        s = str(num)
        n = len(s)
        res = 0
        
        for length in range(n):
            mx = int(s[0]) if length == 0 else 9
            for prev in range(1, mx + 1):
                if length == 0 and prev == mx:
                    res += self.get(s, n, length + 1, prev, False, k)
                else:
                    res += self.get(s, n, length + 1, prev, True, k)
                    
        return res

    def goodIntegers(self, l: int, r: int, k: int) -> int:
        return self.f(r, k) - self.f(l - 1, k)