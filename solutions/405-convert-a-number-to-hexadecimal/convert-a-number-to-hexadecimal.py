class Solution:
    def toHex(self, num: int) -> str:
        hexas = "0123456789abcdef"
        
        if num == 0:
            return "0"
        if num > 0 and num <= 15:
            return hexas[num]
        
        if num < 0:
            num += 2**32
        
        result = []
        
        while num > 0:
            result.append(hexas[num % 16])
            num //= 16
        
        return ''.join(result[::-1])