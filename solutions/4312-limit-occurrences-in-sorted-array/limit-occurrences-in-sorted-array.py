class Solution:
    def limitOccurrences(self, A: List[int], k: int) -> List[int]:
        i = 0        
        for n in A:
            if i < k or n != A[i - k]:
                A[i] = n
                i += 1                
        while len(A) > i:
            A.pop()
            
        return A