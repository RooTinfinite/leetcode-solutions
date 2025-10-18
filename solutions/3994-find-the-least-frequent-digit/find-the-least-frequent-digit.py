class Solution:
    def getLeastFrequentDigit(self, n: int) -> int:
        s = str(n)
        k = len(s)
        freq = {}
        
        for i in range(k):
            digit = int(s[i])
            if digit in freq:
                freq[digit] += 1
            else:
                freq[digit] = 1
        
        minfreq = float('inf')
        for key, value in freq.items():
            minfreq = min(minfreq, value)
        
        result = 10
        for key, value in freq.items():
            if value == minfreq:
                result = min(result, key)
        
        return result