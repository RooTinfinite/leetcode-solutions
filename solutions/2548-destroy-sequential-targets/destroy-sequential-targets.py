class Solution:
    def destroyTargets(self, xs: List[int], space: int) -> int:
        class_freqs = Counter(x % space for x in xs)
        max_count = max (class_freqs.values())
        return min(x for x in xs if class_freqs [x % space] == max_count)

