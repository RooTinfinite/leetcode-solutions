class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        i, result = 0, []

        for space in spaces:
            result.append(s[i : space])
            i = space

        result.append(s[i :])
        return " ".join(result)