class Solution:
    def reverseWords(self, s: str) -> str:
        a=s.split(" ")
        vowels=set("aeiou")
        vow=lambda x: sum(1 for i in x if i in vowels)
        first=vow(a[0])
        for i in range(1,len(a)):
            if vow(a[i])==first:
                a[i]=a[i][::-1]
        return " ".join(a)
       