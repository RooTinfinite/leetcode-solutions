class Solution(object):
    def vowelStrings(self, words, queries):
        prefix = [0]
        sum_ = 0
        for word in words:
            if word[0] in 'aeiou' and word[-1] in 'aeiou':
                sum_ += 1
            prefix.append(sum_)
        res = []
        for l, r in queries:
            res.append(prefix[r + 1] - prefix[l])
        return res