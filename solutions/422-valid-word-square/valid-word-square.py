class Solution:
    def validWordSquare(self, words: List[str]) -> bool:
        for i in range(len(words)):
            vals = []
            for ii in range(len(words)):
                if i < len(words[ii]): vals.append(words[ii][i])
            if words[i] != "".join(vals): return False 
        return True 