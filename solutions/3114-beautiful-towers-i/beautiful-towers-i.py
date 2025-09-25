class Solution:
    def maximumSumOfHeights(self, maxHeights: List[int], ans = 0) -> int:
        
        for i in range(len(maxHeights)):
            
            ans = max(ans, sum(accumulate(maxHeights[i::-1], min)) + # left  prefix
                           sum(accumulate(maxHeights[i:   ], min)) - # right prefix 
                           maxHeights[i])                            # less the overcount
        return ans