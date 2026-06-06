#           S1: state 1--incr before removal
#           S2: state 2--decr before removal
#           S3: state 3--incr after  removal
#           S4: state 4--decr after  removal

class Solution:
    def longestAlternating(self, nums: List[int]) -> int:  
        
        prvS1, prvS2, prvS3, prvS4, mxLen = 1, 1, 1, 1, 1

        for lft, rgt in pairwise(nums):
            curS1, curS2, curS3, curS4  = 1, 1, 1, 1
            delta = rgt - lft

            if   delta > 0: curS1, curS3 = prvS2 + 1, prvS4 + 1
            elif delta < 0: curS2, curS4 = prvS1 + 1, prvS3 + 1
            if prvS1 > curS3: curS3 = prvS1
            if prvS2 > curS4: curS4 = prvS2
            prvS1, prvS2, prvS3, prvS4 = curS1, curS2, curS3, curS4

            mxLen = max(mxLen, prvS1, prvS2, prvS3, prvS4)
        
        return mxLen