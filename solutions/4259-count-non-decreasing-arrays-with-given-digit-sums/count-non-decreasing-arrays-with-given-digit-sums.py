class Solution:
    def countArrays(self, digitSum: list[int]) -> int:
        MOD = 10**9 + 7
        N = len(digitSum)

        helper = [[] for _ in range(51)]
        for num in range(5001):
            s = sum(map(int, str(num)))
            helper[s].append(num)


        previous = [[num, 1] for num in helper[digitSum[-1]]]

        for i in range(N-2, -1, -1):
            prevNums = [p[0] for p in previous]
            prevCnts = [p[1] for p in previous]

            suffix = [0] * (len(prevCnts) + 1)
            for j in range(len(prevCnts)-1, -1, -1):
                suffix[j] = (suffix[j+1] + prevCnts[j]) % MOD

            nxt = []
            for num in helper[digitSum[i]]:
                ind = bisect.bisect_left(prevNums, num)
                count = suffix[ind]  
                nxt.append([num, count])

            previous = nxt

        return sum(cnt for _, cnt in previous) % MOD