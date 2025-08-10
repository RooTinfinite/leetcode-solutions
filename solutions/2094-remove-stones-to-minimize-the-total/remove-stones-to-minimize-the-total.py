import heapq

class Solution:
    def minStoneSum(self, piles: list[int], k: int) -> int:
        h = [-p for p in piles]
        heapq.heapify(h)
        for _ in range(k):
            x = -heapq.heappop(h)
            x -= x // 2
            heapq.heappush(h, -x)
        return -sum(h)