class Solution:
    def distinctDifferenceArray(self, nums: List[int]) -> List[int]:    #  Example:   nums = [3,2,3,4,2]
                                                                        #  
        pref, suff = defaultdict(int), Counter(nums)                    #   pref, suff = {}, {2:2, 3:2, 4:1}

        cur = -len(suff)                                                #  cur = -3

        for i, n in enumerate(nums):                                    #  n  cur  pref           suff           nums
            pref[n]+= 1                                                 # ––– –––  ––––––––       –––––––        –––––––
            suff[n]-= 1                                                 #      -3  {2:0,3:0,4:0}  {2:2,3:2,4:1}  [| 3, 2, 3, 4, 2]
            cur = nums[i] = cur + (pref[n] == 1) + (suff[n] == 0)       #  3   -2  {2:0,3:1,4:0}  {2:2,3:1,4:1}  [-2,| 2, 3, 4, 2]
                                                                        #  2   -1  {2:1,3:1,4:0}  {2:1,3:1,4:1}  [-2,-1,| 3, 4, 2]
        return  nums                                                    #  3    0  {2:1,3:2,4:0}  {2:1,3:0,4:1}  [-2,-1, 0,| 4, 2]
                                                                        #  4    2  {2:1,3:2,4:1}  {2:1,3:0,4:0}  [-2,-1, 0, 2,| 2]
                                                                        #  2    3  {2:2,3:2,4:1}  {2:0,3:0,4:0}  [-2,-1, 0, 2, 3|]