class Solution:
    def maxProfit(self, prices: list[int], strat: list[int], k: int) -> int:
        n = len(prices)
        h = k // 2

        sp = [s * p for s, p in zip(strat, prices)]
        base = sum(sp)

        if n == k:
            change = sum(prices[h:]) - base
            return base + max(0, change)

        win_orig = sum(sp[:k])
        win_mod = sum(prices[h:k])
        max_ch = win_mod - win_orig

        for i in range(1, n - k + 1):
            win_orig += sp[i+k-1] - sp[i-1]
            win_mod += prices[i+k-1] - prices[i-1+h]
            max_ch = max(max_ch, win_mod - win_orig)

        return base + max(0, max_ch)