
class Solution:
    def minOperations(self, a: List[int], k: int) -> int:
        a = [x % k for x in a]
        E = a[::2]
        O = a[1::2]

        def top_two(a):
            cnt = [0] * (3*k)
            tot = [0] * (3*k)
            for x in a:
                for off in (0, k, 2 * k):
                    cnt[x + off] += 1
                    tot[x + off] += x + off

            pcnt = list(accumulate(cnt)) + [0]
            ptot = list(accumulate(tot)) + [0]

            m, M = (k - 1) // 2, k // 2
            costs = []
            for t in range(k):
                c = t + k
                # left half [c - m, c], right half [c + 1, c + M]
                left  = c * (pcnt[c] - pcnt[c - m - 1]) - (ptot[c] - ptot[c - m - 1])
                right = (ptot[c + M] - ptot[c]) - c * (pcnt[c + M] - pcnt[c])
                costs.append((left + right, t))

            return [(x, cost) for cost, x in nsmallest(2, costs)]

        e2 = top_two(E)
        o2 = top_two(O)

        if e2[0][0] != o2[0][0]:
            return e2[0][1] + o2[0][1]
        else:
            return min(e2[0][1] + o2[1][1], e2[1][1] + o2[0][1])