class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        j=0
        flag=False
        tmp=1
        res=0
        l=len(searchWord)
        if sentence[j:j+l]==searchWord:
            flag=True
            return tmp
        for i in range(len(sentence)):
            if sentence[i:i+l]==searchWord and sentence[i-1]==" ":
                flag=True
                res = i
                break
        
        for i in range(len(sentence)):
            if sentence[i]==" ":
                tmp+=1
            if i==res:
                break
        if flag:
            return tmp
        else:
            return -1