from typing import List


def binary_search(
    func_,  # condition function
    first=True,  # else last
    target=True,  # else False
    left=0,
    right=2**31 - 1,
) -> int:
    # https://leetcode.com/discuss/general-discussion/786126/
    # ASSUMES THAT THERE IS A TRANSITION
    # MAY HAVE ISSUES AT THE EXTREMES

    def func(val):
        # if first True or last False, assume search space is in form
        # [False, ..., False, True, ..., True]

        # if first False or last True, assume search space is in form
        # [True, ..., True, False, ..., False]
        # for this case, func will now be negated
        if first ^ target:
            return not func_(val)
        return func_(val)

    while left < right:
        mid = (left + right) // 2
        if func(mid):
            right = mid
        else:
            left = mid + 1
    if first:  # find first True
        return left
    else:  # find last False
        return left - 1


class Solution:
    def minDifference(self, nums: List[int]) -> int:
        # left, right, count (1 or 2)
        n = len(nums)
        
        if nums.count(-1) == 0:
            return max(abs(a-b) for a,b in zip(nums, nums[1:]))
        if nums.count(-1) == n:
            return 0
        
        arr = []
        
        if nums[-1] == -1:
            while nums[-1] == -1:
                nums.pop()
            arr.append((nums[-1], nums[-1], 1))
            
        nums.reverse()
        if nums[-1] == -1:
            while nums[-1] == -1:
                nums.pop()
            arr.append((nums[-1], nums[-1], 1))
        
        maxdiff = 0
        
        prev_val = nums[0]
        prev_idx = 0
        for i,x in enumerate(nums[1:], start=1):
            if x != -1:
                if i - prev_idx == 1:
                    maxdiff = max(maxdiff, abs(x - prev_val))
                elif i - prev_idx == 2:
                    left = min(prev_val, x)
                    right = max(prev_val, x)
                    arr.append((left, right, 1))
                else:
                    left = min(prev_val, x)
                    right = max(prev_val, x)
                    arr.append((left, right, 2))
                prev_val = x
                prev_idx = i
                
        def func(target_diff):
            if target_diff < maxdiff:
                return False
            
            xval = 10**10 + 10
            yval = -10**10 - 10
            for a,b,c in arr:
                xval = min(xval, a + target_diff)   # can be smaller and ok
                yval = max(yval, b - target_diff)   # can be larger and ok
            
            for a,b,c in arr:
                if c == 1:
                    if abs(a - xval) <= target_diff and abs(b - xval) <= target_diff:
                        continue
                    if abs(a - yval) <= target_diff and abs(b - yval) <= target_diff:
                        continue
                    return False
                if c == 2:
                    if abs(a - xval) <= target_diff and abs(b - yval) <= target_diff and abs(yval - xval) <= target_diff:
                        continue
                    if abs(a - yval) <= target_diff and abs(b - xval) <= target_diff and abs(yval - xval) <= target_diff:
                        continue
                    if abs(a - xval) <= target_diff and abs(b - xval) <= target_diff:
                        continue
                    if abs(a - yval) <= target_diff and abs(b - yval) <= target_diff:
                        continue
                    return False
            return True
        
        return binary_search(func, first=True, target=True, left=0, right=10**10 + 10)
        
            
        
        
        