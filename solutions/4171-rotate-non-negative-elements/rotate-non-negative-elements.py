class Solution:
    def rotateElements(self, nums: List[int], k: int) -> List[int]:
        index = []
        val = []
        for each in range(len(nums)):
            if nums[each] >= 0:
                val.append(nums[each])
                index.append(each)
        if not val:
            return nums

        k = k % len(val)
        val = val[k:] + val[:k]
        for i in range(len(index)):
            nums[index[i]] = val[i]
        return nums