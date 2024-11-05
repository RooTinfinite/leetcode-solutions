class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        arr = [math.ceil(success / potion) for potion in potions]
        arr.sort()

        res = []
        for spell in spells:
            l, r, M = 0, len(arr) - 1, 0
            while l <= r:
                m = (l + r) // 2
                if arr[m] <= spell:
                    l = m + 1
                    M = l
                else:
                    r = m - 1
            res.append(M)

        return res