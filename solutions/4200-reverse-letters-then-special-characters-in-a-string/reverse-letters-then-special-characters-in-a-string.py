class Solution:
    def reverseByType(self, s: str) -> str:

        def rev(q: List(int))-> None:
            for i in range(len(q)//2):
                s[q[i]], s[q[~i]] = s[q[~i]], s[q[i]]
            return


        s, alphQ, specQ = list(s), [], []           # <-- 1)

        for idx in range(len(s)):
            if s[idx].isalpha(): alphQ.append(idx)  # <-- 2)
            else: specQ.append(idx)

        rev(alphQ)                                  # <-- 3)
        rev(specQ)
        
        return ''.join(s)                           # <-- 4)