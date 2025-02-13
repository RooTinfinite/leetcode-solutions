class Solution:
    def diStringMatch(self, s: str) -> List[int]:
        ans = []
        a , b = 0 , len(s)
        
        for i in s:
            if(i == 'I'):
                ans.append(a)
                a += 1
            else:
                ans.append(b)
                b -= 1
        
        if(s[-1] == 'D'):
            ans.append(a)
        else:
            ans.append(b)
                       
        return ans