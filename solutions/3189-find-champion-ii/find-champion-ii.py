class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        
        if not edges: return (n==1) -1

        _, sup = zip(*edges)
 
        roots = set(range(n))- set(sup)
        
        if len(roots) == 1: return roots.pop()
        
        return -1