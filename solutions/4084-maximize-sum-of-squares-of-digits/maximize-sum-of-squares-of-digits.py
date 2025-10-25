class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:

        nines, digit = divmod(sum, 9)
        
        if nines + (digit >0)  > num: return ''
        ans = ''.join(['9'] * nines)

        if nines == num: return ans

        return (ans + str(digit)).ljust(num,'0')
        