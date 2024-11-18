class Solution:
    @staticmethod
    def mod1(i: int, n: int) -> int:
        return i - ((-(1 if i >= n else 0)) & n)
    
    @staticmethod
    def decrypt(code: list[int], k: int) -> list[int]:
        n = len(code)
        
        if k < 0:
            s = sum(code[i] for i in range(n + k, n))
            
            for i in range(n):
                code[i] <<= 16
            
            for i in range(n):
                v = code[i] >> 16
                code[i] += s
                j = Solution.mod1(n + k + i, n)
                s += v - (code[j] >> 16)
            
            for i in range(n):
                code[i] &= 0x3FFF
                
        elif k > 0:
            s = sum(code[i] for i in range(k))
            
            for i in range(n):
                code[i] <<= 16
            
            for i in range(n):
                v = code[i] >> 16
                j = Solution.mod1(i + k, n)
                s += (code[j] >> 16) - v
                code[i] += s
            
            for i in range(n):
                code[i] &= 0x3FFF
                
        else:
            code = [0] * n
            
        return code