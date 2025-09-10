class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:

        # 1) Remaining capacity per bag
        rem = [c - r for c, r in zip(capacity, rocks)]
        
        # 2) Sort by ascending need
        rem.sort()
        
        # 3) Greedily fill
        filled = 0
        for need in rem:
            if additionalRocks >= need:
                additionalRocks -= need
                filled += 1
            else:
                break
        
        return filled