class Solution:
    def spellchecker(self, W: List[str], Q: List[str]) -> List[str]:
        orig, lcase, mask = set(W), defaultdict(), defaultdict()
        regex = r'[aeiou]'
        for i in range(len(W)-1,-1,-1):
            word = W[i]
            wlow = word.lower()
            lcase[wlow] = word
            mask[re.sub(regex, '*', wlow)] = word
        for i in range(len(Q)):
            query = Q[i]
            qlow = query.lower()
            qmask = re.sub(regex, '*', qlow)
            if query in orig: continue
            elif qlow in lcase: Q[i] = lcase[qlow]
            elif qmask in mask: Q[i] = mask[qmask]
            else: Q[i] = ""
        return Q