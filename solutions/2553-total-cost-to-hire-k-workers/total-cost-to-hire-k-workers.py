class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        n = len(costs)
        total = 0
        pq = []
        
        left = 0
        right = n - 1
        
        for i in range(candidates):
            if left <= right:
                heapq.heappush(pq, (costs[left], left))
                left += 1
            if left <= right:
                heapq.heappush(pq, (costs[right], right))
                right -= 1

        for i in range(k):
            cost, index = heapq.heappop(pq)
            total += cost

            if index < left:
                if left <= right:
                    heapq.heappush(pq, (costs[left], left))
                    left += 1
            else:
                if left <= right:
                    heapq.heappush(pq, (costs[right], right))
                    right -= 1

        return total