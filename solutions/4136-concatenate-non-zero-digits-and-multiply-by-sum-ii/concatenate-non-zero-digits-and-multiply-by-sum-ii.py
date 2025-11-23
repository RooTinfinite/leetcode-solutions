class Solution:
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        MOD = 10**9 + 7
        n = len(s)

        nonZeroCount = [0] * (n + 1)
        prefixValue = [0] * (n + 1)
        prefixDigitSum = [0] * (n + 1)
        pow10 = [1] * (n + 1)

        for i in range(1, n + 1):
            pow10[i] = (pow10[i - 1] * 10) % MOD

        for i in range(n):
            digit = ord(s[i]) - ord('0')

            nonZeroCount[i + 1] = nonZeroCount[i]
            prefixValue[i + 1] = prefixValue[i]
            prefixDigitSum[i + 1] = prefixDigitSum[i]

            if digit != 0:
                nonZeroCount[i + 1] += 1
                prefixValue[i + 1] = (prefixValue[i] * 10 + digit) % MOD
                prefixDigitSum[i + 1] += digit

        ans = []
        for l, r in queries:
            count = nonZeroCount[r + 1] - nonZeroCount[l]
            digitSum = prefixDigitSum[r + 1] - prefixDigitSum[l]

            if count == 0:
                x = 0
            else:
                left = (prefixValue[l] * pow10[count]) % MOD
                x = (prefixValue[r + 1] - left + MOD) % MOD

            ans.append((x * digitSum) % MOD)

        return ans