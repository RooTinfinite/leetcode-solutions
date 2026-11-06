
class Solution:
    def countMagicalPairs(self, s: str) -> int:
        n = len(s)
        res = 0

        for i in range(n):
            seen1 = [False] * 27
            l = [0] * 27
            r = [0] * 27
            ans1 = 0

            for j in range(i, -1, -1):
                c = ord(s[j]) - ord('a')

                if not seen1[c]:
                    seen1[c] = True
                    ans1 += 1

                l[ans1] += 1

            seen2 = [False] * 27
            ans2 = 0

            for k in range(i + 1, n):
                c = ord(s[k]) - ord('a')

                if not seen2[c]:
                    seen2[c] = True
                    ans2 += 1

                r[ans2] += 1

            for x in range(1, 27):
                res += l[x] * r[x]

        return res