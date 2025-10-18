class Solution:
    def simpleGraphExists(self, degrees: List[int]) -> bool:

        degrees = [d for d in degrees if d > 0]
        sm, n = sum(degrees), len(degrees)
        end = n - 1

        if sm % 2 == 1 or sm > n * (n - 1): return False
        
        degrees.sort()   
        prefix = list(accumulate(degrees)) 

        for k in range(n):
            if k <= degrees[0] - 1: 
                rght = (k+1) * end

            elif k >= degrees[n - (k+1)] - 2:
                rght = (k+1) * k + prefix[end - k - 1] 

            else:
                idx = bisect_right(degrees, k+2)    
                rght = (k+1) * (prefix[idx - 1] + end - idx)

            left = prefix[end] - prefix[end - k - 1]

            if left > rght:
                return False

        return True