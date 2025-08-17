class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        def isBalanced(num):
            d = {}
            while num > 0:
                last = num % 10

                if last not in d: d[last] = 1
                else: d[last] += 1
                
                num = num // 10
            
            return all(i == d[i] for i in d)
        
        start = n + 1
        while not isBalanced(start):
            start += 1
        
        return start
                