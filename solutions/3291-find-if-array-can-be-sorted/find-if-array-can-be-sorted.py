class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        groups = []
        curr = []
        currBits = None
        for num in nums:
            if not currBits:
                currBits = num.bit_count()
            if num.bit_count() == currBits:
                curr.append(num)
            else:
                currBits = num.bit_count()
                groups.append(curr)
                curr = [num]
        if curr:
            groups.append(curr)

        out = []
        for g in groups:
            out += sorted(g)
        return out == sorted(nums)