from collections import deque

class Solution:
    def maximumCostSubstring(self, s: str, chars: str, vals) -> int:
        dico={chars[i] : vals[i] for i in range(len(vals))}
        alphabet= {chr(i): i - 96 for i in range(97, 123)}
        print(alphabet)
        queue=deque([])
        sum=0
        output=0
        for c in s:
            if c in dico:
                sum+=dico[c]
                queue.append(dico[c])
            else:
                sum+=alphabet[c]
                queue.append(alphabet[c])
            if sum>output:
                output=sum
            elif sum<0:
                while queue and sum<0:
                    sum-=queue.popleft()
        return output