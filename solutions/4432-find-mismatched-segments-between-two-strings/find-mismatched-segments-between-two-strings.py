class Solution(object):
    def findMismatchedSegments(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: List[List[str]]
        """
        ans=[]
        i=0
        while i<len(s1):
            if s1[i]==s2[i]:
                i+=1
                continue
            start=i
            while i<len(s1) and s1[i]!=s2[i]:
                i+=1
            sub1=s1[start:i]
            sub2=s2[start:i]
            ans.append([sub1,sub2])
        return ans
