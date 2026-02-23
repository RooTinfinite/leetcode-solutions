class Solution:
    def wordSquares(self, words):
        ans = []
        n = len(words)

        for i in range(n):
            for j in range(n):
                if j == i:
                    continue
                for k in range(n):
                    if k == i or k == j:
                        continue
                    for l in range(n):
                        if l == i or l == j or l == k:
                            continue

                        top = words[i]
                        left = words[j]
                        right = words[k]
                        bottom = words[l]

                        if (top[0] == left[0] and
                            top[3] == right[0] and
                            bottom[0] == left[3] and
                            bottom[3] == right[3]):
                            ans.append([top, left, right, bottom])

        ans.sort()
        return ans