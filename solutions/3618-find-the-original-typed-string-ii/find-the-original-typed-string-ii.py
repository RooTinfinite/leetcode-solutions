class Solution:
    def possibleStringCount(self, word: str, k: int) -> int:
        MOD = int(1e9+7)        
        consecutive, prev = [1], word[0]

        for elem in word[1:]:
            if elem == prev:
                consecutive[-1] += 1
            else:
                consecutive.append(1)
                prev = elem

        n = len(consecutive)

        # all the possible ways of creating strings of any length
        prod = reduce(lambda x, acc: (x * acc) % MOD, consecutive)

        # each group contribute with one mandatory character,
        # so there are len(consecutive) mandatory characters
        k -= len(consecutive)

        if k <= 0:
            return prod

        dp = [0 for _ in range(k)]
        dp[0] = 1

        for group in consecutive:
            a = [0 for _ in range(k)]

            # any point can be a start for this window
            for i in range(k):
                a[i] += dp[i]

                if i + group < k:
                    a[i + group] -= dp[i]
            dp = list(accumulate(a))
        return (prod - sum(dp)) % MOD