class Solution(object):
    def stringSequence(self, target):
        """
        :type target: str
        :rtype: List[str]
        """
        ans=['a']
        i=0
        j=0
        while ans[-1]!=target:
            if ans[-1][j]==target[i]:
                ans.append(ans[-1][:j+1]+'a')
                j+=1
                i+=1
            else:
                ans.append(ans[-1][:j]+chr(ord(ans[-1][j])+1))
        return ans

        