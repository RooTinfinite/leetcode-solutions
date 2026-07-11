class Solution:
    def sortVowels(self, s: str) -> str:
        s_list=list(s)
        freq_s={}
        v=['a','e','i','o','u']
        for i in s:
            if i in v:
                if i in freq_s:
                    freq_s[i]+=1
                else:
                    freq_s[i]=1   
        ans=[]
        for x in freq_s:
            for i in range(freq_s[x]):
                ans.append(x)
        ans=sorted(ans,key=lambda x:(-freq_s[x]))
        j=0
        for i in range(len(s_list)):
            if j==len(ans):
                break
            if s_list[i] in v:
                s_list[i] = ans[j]
                j+=1
        return "".join(s_list)            

           
            
                
