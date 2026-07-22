class Solution:
    def minLights(self, l: List[int]) -> int:
        n = len(l)
        li = [0] * n

        mx = 0
        for i in range(n):
            if mx > 0:
                li[i] = -1

            if l[i] > 0:
                mx = max(l[i], mx - 1)
                if mx > 0:
                    li[i] = -1
            else:
                if mx > 0:
                    li[i] = -1
                mx -= 1

        mx = 0
        for i in range(n - 1, -1, -1):
            if mx > 0:
                li[i] = -1

            if l[i] > 0:
                mx = max(l[i], mx - 1)
                if mx > 0:
                    li[i] = -1
            else:
                if mx > 0:
                    li[i] = -1
                mx -= 1

        count = 0
        ans = 0

        for x in li:
            if x != -1:
                count += 1
            else:
                ans += (count + 2) // 3
                count = 0

        if count:
            ans += (count + 2) // 3

        return ans