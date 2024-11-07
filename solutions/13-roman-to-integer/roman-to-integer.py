class Solution:
    @staticmethod
    def calc_scale(c: str, a1: str, a2: str) -> int:
        return -1 if c == a1 or c == a2 else 1
        
    def romanToInt(self, s: str) -> int:
        result = 0
        
        for n in range(len(s)):
            match s[n]:
                case 'M':
                    result += 1000
                case 'D':
                    result += 500
                case 'C':
                    result += 100 * self.calc_scale(s[n+1] if n+1 < len(s) else '', 'M', 'D')
                case 'L':
                    result += 50
                case 'X':
                    result += 10 * self.calc_scale(s[n+1] if n+1 < len(s) else '', 'C', 'L')
                case 'V':
                    result += 5
                case 'I':
                    result += 1 * self.calc_scale(s[n+1] if n+1 < len(s) else '', 'X', 'V')
        
        return result