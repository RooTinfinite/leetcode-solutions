class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:

        N, ans = range(len(queries[0])), []

        f = lambda x,y: sum(x[i] != y[i] for i in N) < 3  # boolean function that returns whether
                                                          # x and y are within two edits
        for q in queries:                                 
            for d in dictionary:
                if f(q,d):
                    ans.append(q)
                    break
        return  ans