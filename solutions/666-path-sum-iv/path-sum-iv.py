class Solution:
    def pathSum(self, nums: List[int]) -> int:
        d = defaultdict(lambda: defaultdict(lambda: 0))
        for n in nums:
            val = n%10
            n //= 10
            pos = n%10
            n //= 10
            depth = n

            d[depth][pos] = val
        
        self.ans = 0        
        def solve(depth, pos, res):

            nextPosLeft = pos * 2 - 1
            nextPosRight = pos * 2

            if depth+1 not in d or nextPosLeft not in d[depth+1] and nextPosRight not in d[depth+1]:
                self.ans += res+d[depth][pos]
                return
            
            if nextPosLeft in d[depth+1]:
                solve(depth+1, nextPosLeft, res+d[depth][pos])

            if nextPosRight in d[depth+1]:
                solve(depth+1, nextPosRight, res+d[depth][pos])

        solve(1,1,0)
        return self.ans