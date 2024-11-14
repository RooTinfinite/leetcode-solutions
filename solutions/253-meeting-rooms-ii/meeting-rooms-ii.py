import heapq

class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        def solve(arr):
            pq = []
            ans = 0
            arr.sort(key= lambda x: x[0])
            for idx, [i,j] in enumerate(arr):

                if len(pq) == 0 or pq[0] > i:
                    heapq.heappush(pq, j)
                else:
                    heapq.heappop(pq)
                    heapq.heappush(pq, j)

            ans = max(ans, len(pq))
            return ans

        return solve(intervals)


        