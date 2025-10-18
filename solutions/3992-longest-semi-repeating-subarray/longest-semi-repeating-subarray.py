class Solution:
    def longestSubarray(self, nums: List[int], k: int) -> int:
        window = Counter()
        n_repeated_elems = 0

        result = 0
        i = 0
        for j, elem in enumerate(nums):
            window[elem] += 1
            if window[elem] == 2:
                n_repeated_elems += 1
            
            while n_repeated_elems > k:
                elem_to_remove = nums[i]
                i += 1
                window[elem_to_remove] -= 1

                if window[elem_to_remove] == 1:
                    n_repeated_elems -= 1
                elif window[elem_to_remove] == 0:
                    window.pop(elem_to_remove)

            result = max(result, j - i + 1)
        
        return result