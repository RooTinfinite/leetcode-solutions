class Solution:
    def maxPoints(self, t1: List[int], t2: List[int], k: int) -> int:

        n = len(t1)
        gain = []
        for i in range(0, n):
            heappush(gain, (-(t1[i] - t2[i]), -t1[i], i))

        skip = set()
        ans = 0
        while gain:
            waste, val, ind = heappop(gain)
            if waste > 0 and k <= 0:
                break
            ans += t1[ind]
            skip.add(ind)
            k -= 1

        for i in range(0, n):
            if i not in skip:
                ans += t2[i]

        return ans

        

        

            
                