class Solution:
    def isCovered(self, ranges: list[list[int]], left: int, right: int) -> bool:
        diff = [0] * 52
        for start, end in ranges:
            diff[start] += 1
            diff[end + 1] -= 1
        curr = 0
        for x in range(1, 51):
            curr += diff[x]
            if left <= x <= right and curr == 0:
                return False
        return True