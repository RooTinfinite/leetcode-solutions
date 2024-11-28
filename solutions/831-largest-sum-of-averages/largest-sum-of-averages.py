class Solution:
    def largestSumOfAverages(self, nums: List[int], k: int) -> float:
        
        @functools.lru_cache(None)
        def dfs(i,k):

            if k == 1:
                return sum(nums[i:])/len(nums[i:]) #Calculate sum for the remaining elements

            maxAvg = 0

            for j in range(i+1, len(nums)): #Try paritioning at each index and calculate average

                avg = sum(nums[i:j])/len(nums[i:j])

                subarrayAvg = avg + dfs(j, k-1) #Call with the next index (j) after partition

                maxAvg = max(maxAvg, subarrayAvg)

            return maxAvg

        return dfs(0,k)
        

        