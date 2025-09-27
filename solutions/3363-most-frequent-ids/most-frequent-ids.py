class Solution:
    def mostFrequentIDs(self, nums: List[int], freq: List[int]) -> List[int]:
        pq = []
        cnt = Counter()
        ans = []
        for x, f in zip(nums, freq): 
            cnt[x] += f
            while pq and cnt[pq[0][1]] + pq[0][0] != 0: heappop(pq)
            heappush(pq, (-cnt[x], x))
            ans.append(-pq[0][0])
        return ans 