class Solution:
    def solve(self, s, encCost, flatCost, start, end):
        l = end - start + 1
        
        count = 0
        for i in range(start, end + 1):
            if s[i] == '1':
                count += 1
        
        if count:
            cost = encCost * l * count
        else:
            cost = flatCost
        
        mid = (start + end) // 2
        
        if l % 2 == 0:
            cost1 = self.solve(s, encCost, flatCost, start, mid)
            cost2 = self.solve(s, encCost, flatCost, mid + 1, end)
            cost = min(cost, cost1 + cost2)
        
        return cost

    def minCost(self, s: str, encCost: int, flatCost: int) -> int:
        return self.solve(s, encCost, flatCost, 0, len(s) - 1)