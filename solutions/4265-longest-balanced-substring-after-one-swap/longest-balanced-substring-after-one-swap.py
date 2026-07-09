class Solution:
    def longestBalanced(self, s: str) -> int:
        n = len(s)
        z, o, diff = [0]*n, [0]*n, [0]*n
        cnt0 = cnt1 = 0

        for i in range(n):
            if s[i] == '0': cnt0 += 1
            else: cnt1 += 1
            z[i], o[i], diff[i] = cnt0, cnt1, cnt1 - cnt0

        maxLen = 0
        ind, ind0, ind1 = {0: -1}, {}, {}

        for i in range(n):
            pref = diff[i]
            if pref in ind:
                maxLen = max(maxLen, i - ind[pref])
            
            if (pref + 2) in ind:
                j = ind[pref + 2]
                sub1s = o[i] - (o[j] if j >= 0 else 0)
                if cnt1 > sub1s: maxLen = max(maxLen, i - j)
                elif (pref + 2) in ind1: maxLen = max(maxLen, i - ind1[pref + 2])
            
            if (pref - 2) in ind:
                j = ind[pref - 2]
                sub0s = z[i] - (z[j] if j >= 0 else 0)
                if cnt0 > sub0s: maxLen = max(maxLen, i - j)
                elif (pref - 2) in ind0: maxLen = max(maxLen, i - ind0[pref - 2])
            
            if pref not in ind: ind[pref] = i
            if pref not in ind0 and z[i] > 0: ind0[pref] = i
            if pref not in ind1 and o[i] > 0: ind1[pref] = i

        return maxLen