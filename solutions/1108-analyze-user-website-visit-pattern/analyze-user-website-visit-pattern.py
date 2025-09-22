class Solution:
    def mostVisitedPattern(self, username: List[str], timestamp: List[int], website: List[str]) -> List[str]:
        graph = defaultdict(list)
        for u, t, w in sorted(zip(username, timestamp, website)):
            graph[u].append(w)
        
        counter = Counter()
        for u, routes in graph.items():
            for triple in set(itertools.combinations(routes, 3)):
                counter[triple]+=1
        
        pattern, count = None, 0
        for pat, c in counter.items():
            if c > count:
                pattern = pat
                count = c
            elif c == count and pattern > pat:
                pattern = pat
                
        return pattern
            
        