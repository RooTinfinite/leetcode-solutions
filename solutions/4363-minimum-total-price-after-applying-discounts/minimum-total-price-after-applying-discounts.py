class Solution:
    def minPrice(self, prices, discounts):
        prices.sort()
        discounts.sort()

        p1 = len(prices) - 1
        p2 = len(discounts) - 1

        total = 0

        while p1 >= 0 and p2 >= 0:
            total += prices[p1] * (100 - discounts[p2]) / 100
            p1 -= 1
            p2 -= 1

        while p1 >= 0:
            total += prices[p1]
            p1 -= 1

        return total