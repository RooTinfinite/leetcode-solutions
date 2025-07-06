class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        return sum([math.comb(n, 2) for n in collections.Counter(nums).values()])      