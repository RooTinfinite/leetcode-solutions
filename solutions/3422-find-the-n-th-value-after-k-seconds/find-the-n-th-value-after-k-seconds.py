class Solution:
    def valueAfterKSeconds(self, n: int, k: int) -> int:
        Sum = [1] * n
        for t in range(k):
            for i in range(1 , n):
                Sum[i] = (Sum[i] + Sum[i - 1]) % 1000000007
        return Sum[n - 1]