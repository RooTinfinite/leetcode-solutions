class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        graph = {i: [] for i in range(n)}
        for i in range(n - 1):
            graph[i].append((i + 1, 1))
        
        def ans():
            distance=[float('inf')]*n
            distance[0]=0
            dn=[(0,0)]
            while dn:
                current , u= heapq.heappop(dn)
                if current<distance[u]:
                    continue
                for v, w in graph[u]:
                    d= current+w
                    if d < distance[v]:
                        distance[v] = d
                        heapq.heappush(dn, (d, v))
            return distance[n - 1]

        result=[]
        for u ,v in queries:
            graph[u].append((v, 1))
            spl=ans()
            result.append(spl)
        return result