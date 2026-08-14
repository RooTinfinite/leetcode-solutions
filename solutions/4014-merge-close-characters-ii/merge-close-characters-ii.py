class Solution:
    def mergeCharacters(self, s: str, k: int) -> str:
        res, ch = [], set()
        for c in s:
            if c in ch:
                continue
            if len(ch) == k:
                ch.remove(res[-k])
            ch.add(c)
            res.append(c)
        return ''.join(res)