class Solution:
    def maxScore(self, n: int, k: int, stayScore  : List[List[int]], 
                                       travelScore: List[List[int]]) -> int:

        curr, prev = [0] * n, [0] * n

        for day in range(k-1, -1, -1):

            for city in range(n):
                move = max(map(sum, zip(prev, travelScore[city])))
                stay = max(curr[city], prev[city] + stayScore[day][city])

                curr[city] = max(move, stay)

            prev, curr = curr, prev
 
        return max(prev)