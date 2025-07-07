class Solution:
    def maxEvents(self, events) -> int:
        events.sort(key=lambda x: (x[1], x[0]))
        c = 0
        parent = dict()

        def dsfind(n):
            if n not in parent:
                return n
            parent[n] = dsfind(parent[n])
            return parent[n]

        for b, e in events:
            a = dsfind(b)
            if a <= e:
                c += 1
                parent[a] = a + 1

        return c