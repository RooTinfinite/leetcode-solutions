from sortedcontainers import SortedList

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:        
        n = len(nums)

        less_than_median = SortedList()
        greater_than_median = SortedList()
        ltm_sum = 0
        gtm_sum = 0

        for idx in range(k - 1):
            less_than_median.add(nums[idx])
            ltm_sum += nums[idx]
        median_split_size = k//2

        ans = inf

        for lidx in range(n - k + 1):
            new_num = nums[lidx + k - 1]
            less_than_median.add(new_num)
            ltm_sum += new_num
            
            while len(less_than_median) > median_split_size:
                max_val = less_than_median[-1]
                less_than_median.remove(max_val)
                ltm_sum -= max_val
                greater_than_median.add(max_val)
                gtm_sum += max_val
            while greater_than_median[0] < less_than_median[-1]:
                less_max_val = less_than_median[-1]
                greater_min_val = greater_than_median[0]
                less_than_median.remove(less_max_val)
                greater_than_median.remove(greater_min_val)
                ltm_sum -= less_max_val
                gtm_sum -= greater_min_val
                less_than_median.add(greater_min_val)
                greater_than_median.add(less_max_val)
                ltm_sum += greater_min_val
                gtm_sum += less_max_val
            
            ans = min(ans, gtm_sum - ltm_sum - (k % 2) * greater_than_median[0])
            
            remove_val = nums[lidx]
            if remove_val in less_than_median:
                less_than_median.remove(remove_val)
                ltm_sum -= remove_val
            elif remove_val in greater_than_median:
                greater_than_median.remove(remove_val)
                gtm_sum -= remove_val
        
        return ans