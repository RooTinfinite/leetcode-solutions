class Solution:
    def minInitialStrength(self, monsters, boosts):
        diff = [0] * (len(monsters) + 1)

        for l, r, val in boosts:
            diff[l] += val
            diff[r + 1] -= val

        for i in range(1, len(diff)):
            diff[i] += diff[i - 1]

        def check(mid):
            curr = mid

            for i in range(len(monsters)):
                total = curr + diff[i]

                if total >= monsters[i]:
                    curr = max(0, curr - monsters[i])
                else:
                    return False

            return True

        l, h = 0, 10**18
        ans = -1

        while l <= h:
            mid = (l + h) // 2

            if check(mid):
                ans = mid
                h = mid - 1
            else:
                l = mid + 1

        return ans