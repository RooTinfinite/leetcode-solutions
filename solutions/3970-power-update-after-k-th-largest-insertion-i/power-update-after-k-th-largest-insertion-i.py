class Solution:
    def powerUpdate(self, nums: list[int], p: int, queries: list[list[int]]) -> list[int]:
        data = SortedList(nums)
        modulo = 10 ** 9 + 7
        result = []
        for val, k in queries:
            data.add(val)
            x = data[-k]
            p = pow(p, x, modulo)
            result.append(p)
        return result