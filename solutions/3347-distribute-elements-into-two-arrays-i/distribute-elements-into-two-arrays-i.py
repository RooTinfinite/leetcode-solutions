class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        arr = [0] * n
        arr[0] = nums[0]
        arr[n - 1] = nums[1]
        idx, revIdx = 0, n - 1
        for i in range(2, n):
            if arr[idx] > arr[revIdx]:
                idx += 1
                arr[idx] = nums[i]
            else:
                revIdx -= 1
                arr[revIdx] = nums[i]
        l, r = revIdx, n - 1
        while l < r:
            arr[l], arr[r] = arr[r], arr[l]
            l += 1
            r -= 1
        return arr