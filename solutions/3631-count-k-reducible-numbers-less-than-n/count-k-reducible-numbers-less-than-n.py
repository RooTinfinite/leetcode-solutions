class Solution:
    def countKReducibleNumbers(self, s: str, k: int) -> int:
        count_1 = s.count("1")
        
        @cache
        def is_count_1_valid(num, limit):
            if num == 1:
                return True
            if limit == 0:
                return False
            return is_count_1_valid(bin(num).count("1"), limit - 1)
        
        res = 0 
        MOD = 10 ** 9 + 7
        for i in range(len(s) - 1, -1, -1):
            if s[i] == '1':
                count_1 -= 1
                length = len(s) - i - 1
                for j in range(length + 1):
                    if is_count_1_valid(count_1 + j, k - 1):
                        res += math.comb(length, j)   ## O(n)
                        res = res % MOD
        return res