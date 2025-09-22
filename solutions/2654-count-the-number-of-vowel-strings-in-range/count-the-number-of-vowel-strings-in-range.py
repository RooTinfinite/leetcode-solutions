class Solution:
    def vowelStrings(self, words: List[str], left: int, right: int) -> int:
        ennikkai=0
        lp="aeiou"
        for j in range(left,right+1):
            if (words[j][0] in lp) and (words[j][-1] in lp):
                ennikkai+=1

        return ennikkai
        