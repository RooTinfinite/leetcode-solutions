class Solution:
    def repeatedCharacter(self, s: str) -> str:
        sett = set()
        for i in s:
            if i not in sett:
                sett.add(i)
            else:
                return i