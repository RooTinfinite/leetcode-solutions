class Solution:
    def minSetSize(self, arr: list[int]) -> int:
        counter, half, length = 0, len(arr) // 2, len(arr)

        for x in sorted(Counter(arr).values(),reverse=True):
            length -= x
            counter += 1
            if length <= half:
                return counter