class Solution:
    def countValidPrefixes(self, s: str) -> int:
        balance = 0
        ans = 0

        for ch in s:
            balance = balance + 1 if ch == '1' else balance - 1

            if -1 <= balance <= 1:
                ans += 1

        return ans