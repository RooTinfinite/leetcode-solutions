class Solution:
    def maxStarSum(self, vals: List[int], edges: List[List[int]], k: int) -> int:
        
        graph = defaultdict(set)
        for i,j in edges:
            if vals[i] > 0 : graph[j].add(i)
            if vals[j] > 0 : graph[i].add(j)
            
        stars = []
        for i,v in enumerate(vals):
            vv = [vals[j] for j in graph[i]]
            vv.sort(reverse=True)
            stars.append(v + sum(vv[0:k]))
            
        return max(stars)