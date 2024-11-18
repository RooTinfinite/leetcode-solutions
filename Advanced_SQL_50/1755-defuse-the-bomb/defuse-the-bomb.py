class Solution:
    def decrypt(self, circ: List[int], k: int) -> List[int]:
        n = len(circ)                   # Circular Array
        result = [0] * n
        
        if k == 0:                      # k = 0
            return result
        
        wsum = 0
        if k > 0:                       # k > 0
            for i in range(k):
                wsum += circ[i + 1]
            result[0] = wsum
            
            for i in range(1, n):
                wsum = wsum - circ[i] + circ[(i + k) % n]
                result[i] = wsum
                
        else:                           # k < 0
            k = -k
            for i in range(k):
                wsum += circ[n - k + i]
            result[0] = wsum
            
            for i in range(1, n):
                wsum = wsum - circ[(n - k + i - 1) % n] + circ[i - 1]
                result[i] = wsum
                
        return result