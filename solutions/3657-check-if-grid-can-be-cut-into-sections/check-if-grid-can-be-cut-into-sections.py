class Solution:
    def checkValidCuts(self, n: int, rectangles: List[List[int]]) -> bool:
        sorted_x = sorted(rectangles, key=lambda p: p[0])
        sorted_y = sorted(rectangles, key=lambda p: p[1])
        
        def merge_intervals(intervals):
            merged = []
            for start, end in intervals:
                if not merged or start >= merged[-1][1]:
                    merged.append([start, end])
                else:
                    merged[-1][1] = max(merged[-1][1], end)
            return merged

        x_intervals = merge_intervals([[x1, x2] for x1, _, x2, _ in sorted_x])
        y_intervals = merge_intervals([[y1, y2] for _, y1, _, y2 in sorted_y])

        return len(x_intervals) > 2 or len(y_intervals) > 2