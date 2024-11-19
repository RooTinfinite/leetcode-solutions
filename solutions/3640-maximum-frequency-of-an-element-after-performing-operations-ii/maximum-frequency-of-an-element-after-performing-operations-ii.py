class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        points_cover = collections.Counter()
        cnt_points = collections.Counter()
        points = set()
        for num in nums:
            cnt_points[num] += 1
            points_cover[num - k] += 1
            points_cover[num + k + 1] -= 1
            points.update({num, num - k, num + k + 1})
        res = points_cover_this_point = 0
        for point in sorted(points):
            points_cover_this_point += points_cover[point]
            res = max(res, cnt_points[point] + 
                        min(points_cover_this_point - cnt_points[point], numOperations))
        return res