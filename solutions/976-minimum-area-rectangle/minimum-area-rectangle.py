class Solution:
    INF = 1e10  
    def minAreaRect(self, points: List[List[int]]) -> int:
        # Convert points to a set for O(1) lookup
        points_set = {(x, y) for x, y in points}
        min_area = Solution.INF  # Initialize minimum area to infinity

        # Iterate over all pairs of points
        for i in range(len(points)):
            for j in range(i + 1, len(points)):
                x1, y1 = points[i]
                x2, y2 = points[j]
                
                # Check if the other two corners of the rectangle exist
                if (x1, y2) in points_set and (x2, y1) in points_set:
                    # Ensure it's not a degenerate rectangle (line or point)
                    if x1 != x2 and y1 != y2:
                        rectangle_area = abs(x1 - x2) * abs(y1 - y2)
                        min_area = min(min_area, rectangle_area)

        # Return the minimum area if a rectangle is found, otherwise return 0
        return 0 if min_area == Solution.INF else min_area

        