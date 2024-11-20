class Solution:
    def minProcessingTime(self, t, v):
        n = len(v)
        t.sort()
        v.sort()
        j = n - 1
        m = len(t)
        ans = 0
        for i in range(m):
            c = 0
            while c < 4:
                ans = max(ans, t[i] + v[j])
                c += 1
                j -= 1
        return ans