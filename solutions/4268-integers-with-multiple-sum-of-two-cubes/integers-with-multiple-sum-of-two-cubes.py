class Solution:
    def findGoodIntegers(self, n: int) -> list[int]:
        mp = defaultdict(int)
        ans = []

        limit = int(n ** (1/3))

        for i in range(1, limit + 1):
            i3 = i * i * i

            for j in range(i, limit + 1):
                s = i3 + j * j * j

                if s > n:
                    break

                mp[s] += 1

        for k, v in mp.items():
            if v >= 2:
                ans.append(k)

        ans.sort()
        return ans