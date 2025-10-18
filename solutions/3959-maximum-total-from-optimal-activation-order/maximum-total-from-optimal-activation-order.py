class Solution:
    def maxTotal(self, value, limit):
        umap = defaultdict(list)
        ans = 0
        n = len(value)

        for i in range(n):
            heapq.heappush(umap[limit[i]], value[i])
            if len(umap[limit[i]]) > limit[i]:
                heapq.heappop(umap[limit[i]])

        for pq in umap.values():
            ans += sum(pq)

        return ans