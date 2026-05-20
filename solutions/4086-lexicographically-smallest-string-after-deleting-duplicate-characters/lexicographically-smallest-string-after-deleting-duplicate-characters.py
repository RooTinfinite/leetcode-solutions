class Solution:
    def lexSmallestAfterDeletion(self, s: str) -> str:
        rem = [0] * 123
        for ch in s:
            rem[ord(ch)] += 1

        cnt = [0] * 123
        st = []

        for ch in s:
            o = ord(ch)
            rem[o] -= 1
            while st:
                t = st[-1]
                ot = ord(t)
                if t > ch and (rem[ot] > 0 or cnt[ot] > 1):
                    cnt[ot] -= 1
                    st.pop()
                else:
                    break
            st.append(ch)
            cnt[o] += 1

        while st:
            o = ord(st[-1])
            if cnt[o] > 1:
                cnt[o] -= 1
                st.pop()
            else:
                break

        return "".join(st)