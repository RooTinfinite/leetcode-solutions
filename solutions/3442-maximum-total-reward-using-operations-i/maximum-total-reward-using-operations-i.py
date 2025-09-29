class Solution:
    def maxTotalReward(self, rewardValues: List[int]) -> int:
        rewardValues.sort()
        n = len(rewardValues)
        max_possible_score = 2 * rewardValues[n - 1]
        
        preDP = [False] * (max_possible_score + 1)
        curDP = [False] * (max_possible_score + 1)
        preDP[0] = True
        
        for i in range(n):
            for j in range(rewardValues[i]):
                curDP[j + rewardValues[i]] |= preDP[j]    
            for j in range(len(preDP)):
                preDP[j] |= curDP[j]
                curDP[j] = False

        ans = 0
        for i in range(len(preDP)):
            if preDP[i]:
                ans = i
        return ans