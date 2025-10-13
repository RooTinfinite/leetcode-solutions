class Solution:
    def concatHex36(self, n: int) -> str:
        # Square and cube of n
        n2 = n * n
        n3 = n * n * n
    
        # Convert to hexadecimal (base 16), uppercase
        hex_part = format(n2, 'X')
    
        # Convert to hexatrigesimal (base 36), uppercase
        base36_chars = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'

        base36_part = ''
        
        num = n3
        while num > 0:
            base36_part = base36_chars[num % 36] + base36_part
            num //= 36
    
        return hex_part + base36_part