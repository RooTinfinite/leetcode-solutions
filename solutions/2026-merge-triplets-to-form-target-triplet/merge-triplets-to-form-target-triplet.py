class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        aa, bb, cc = target
        obtain_a = any(a == aa and b <= bb and c <= cc for a, b, c in triplets)
        obtain_b = any(a <= aa and b == bb and c <= cc for a, b, c in triplets)
        obtain_c = any(a <= aa and b <= bb and c == cc for a, b, c in triplets)
        return obtain_a and obtain_b and obtain_c