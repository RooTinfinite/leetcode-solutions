class Solution:
    def maxPalindromesAfterOperations(self, words, ans = 0) -> int:

        ctr = Counter(chain(*words))
        numPairs = sum(map(lambda x: x//2, ctr.values()))

        for wLen in sorted(map(len,words)):
            numPairs-= (wLen// 2)
            ans+=  numPairs >= 0

        return ans