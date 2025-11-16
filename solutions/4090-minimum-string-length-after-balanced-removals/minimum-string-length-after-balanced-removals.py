class Solution:
    def minLengthAfterRemovals(self, s):
        st = []
        i = 0
        while i < len(s):
            while st and s[i] != st[-1]:
                if i >= len(s):
                    break
                st.pop()
                i += 1
                if i >= len(s):
                    break
            if i < len(s):
                st.append(s[i])
            i += 1
        return len(st)