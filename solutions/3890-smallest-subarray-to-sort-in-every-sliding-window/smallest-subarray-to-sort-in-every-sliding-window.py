class Solution:
    def minSubarraySort(self, nums: List[int], k: int) -> List[int]:
        sl = SortedList(nums[i] for i in range(k))

        def calc(left_index, right_index):
            for i in range(k):
                if nums[left_index + i] != sl[i]:
                    break
            else:
                return 0
            for j in range(k):
                if nums[right_index - j] != sl[-1 - j]:
                    break
            return k - i - j

        result = [calc(0, k - 1)]

        for j in range(k, len(nums)):
            i = j - k
            left_elem = nums[i]
            right_elem = nums[j]
            if left_elem != right_elem:
                sl.remove(left_elem)
                sl.add(right_elem)
            result.append(calc(i + 1, j))

        return result