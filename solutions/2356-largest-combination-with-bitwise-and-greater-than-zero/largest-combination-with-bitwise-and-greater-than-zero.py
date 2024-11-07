BitMax = 24
class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        max_set = 1
        mask = 1
        for shift in range(BitMax):
            count = 0
            for num in candidates:
                if num & mask:
                    count += 1
            if max_set < count:
                max_set = count
            mask <<= 1
        return max_set