class Solution:
    def makeParityAlternating(self, nums: List[int]) -> List[int]:
        n = len(nums)
        if n == 1:
            return [0, 0]

        def solve(start_parity: int) -> (int, int):
            ops = 0
            points = []  # (value, index_id)
            for i, x in enumerate(nums):
                if x & 1 == start_parity ^ (i & 1):
                    points.append((x, i))
                else:
                    ops += 1
                    points.append((x - 1, i))
                    points.append((x + 1, i))

            points.sort()
    
            # minimal range that contains at least one option for each i
            cnt = [0] * n
            best_range = 10 ** 20
            covered = l = 0
            for r in range(len(points)):
                vr, ir = points[r]
                covered += cnt[ir] == 0
                cnt[ir] += 1

                # If all elements are covered try to find best range
                while covered == n:
                    vl, il = points[l]
                    best_range = min(best_range, vr - vl)
                    cnt[il] -= 1
                    covered -= cnt[il] == 0
                    l += 1

            return ops, best_range

        return min(solve(0), solve(1))