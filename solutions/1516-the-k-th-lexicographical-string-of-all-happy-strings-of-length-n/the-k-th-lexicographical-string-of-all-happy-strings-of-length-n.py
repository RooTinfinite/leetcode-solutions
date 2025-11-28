class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        nextLetter = {'a': 'bc', 'b': 'ac', 'c': 'ab'} 
        q = collections.deque(['a', 'b', 'c'])
        while len(q[0]) != n:
            u = q.popleft()    
            for v in nextLetter[u[-1]]:
                q.append(u + v)
        return q[k - 1] if len(q) >= k else ''     