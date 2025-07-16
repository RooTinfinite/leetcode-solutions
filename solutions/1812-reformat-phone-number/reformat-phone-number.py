class Solution:
    def reformatNumber(self, number: str) -> str:
        s = [i for i in number if i.isdigit()]
        res = [s[i: i + 3] for i in range(0, len(s), 3)]
        if len(res[-1]) == 1:
            c = res[-2].pop()
            res[-1].insert(0, c)
        return "-".join("".join(i) for i in res)