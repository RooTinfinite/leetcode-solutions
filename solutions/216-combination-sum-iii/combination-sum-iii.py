class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        def solve(startNumber = 1, numberOfItems = k, total = n):
            if startNumber > total:
                return []

            if numberOfItems == 1:
                if total > 9:
                    return []
                else:
                    return [[total]]

            res = []
            for i in range(startNumber, 10):
                res += [[i] + a for a in solve(i + 1, numberOfItems - 1, total - i)]

            return res

        return solve()

            