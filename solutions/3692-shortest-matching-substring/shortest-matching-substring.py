class Solution:
    def shortestMatchingSubstring(self, s: str, p: str) -> int:
        # KMP
        # Time Complexity: O(n + m)
        # Space Complexity: O(n + m)
        def lps(s):
            n = len(s)
            lps = [0] * n
            j = 0
            for i in range(1, n):
                while j and s[i] != s[j]:
                    j = lps[j-1]
                if s[i] == s[j]:
                    j += 1
                    lps[i] = j
            return lps
        a, b, c = p.split('*')
        na, nb, nc = len(a), len(b), len(c)
        lps_a, lps_b, lps_c = lps(a + '$' + s)[na+1:], lps(b + '$' + s)[nb+1:], lps(c + '$' + s)[nc+1:]
        ans = inf
        i = j = k = 0
        try:
            while i + nb + nc < len(lps_a):
                while lps_a[i] != na:
                    i += 1
                while j < i + nb or lps_b[j] != nb:
                    j += 1
                while k < j + nc or lps_c[k] != nc:
                    k += 1
                ans = min(ans, k - i + na)
                i += 1
        except:
            pass
        return -1 if ans is inf else ans