class Solution:
    def findClosestNumber(self, nums):
        len_nums = len(nums)
        
        min_dist_to_zero = None
        closest_to_zero_num = None

        i = 0
        while (i < len_nums):
            num = nums[i]

            if (min_dist_to_zero is None or abs(num-0) <= min_dist_to_zero):
                closest_to_zero_num = max(num, closest_to_zero_num) if min_dist_to_zero == abs(num-0) else num
                min_dist_to_zero = abs(num-0)

            i += 1

        return closest_to_zero_num