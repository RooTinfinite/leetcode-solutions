from bisect import bisect_left
from collections import defaultdict
class Solution:
    def separateSquares(self, blocks: List[List[int]]) -> float:
        class Action:
            def __init__(self, y_axis, x_start, x_end, kind):
                self.y_axis = y_axis
                self.x_start = x_start
                self.x_end = x_end
                self.kind = kind
            
            def __lt__(self, other):
                return (self.y_axis, self.kind) < (other.y_axis, other.kind)
        
        actions = []
        unique_x = []
        
        for x1, y1, length in blocks:
            x2, y2 = x1 + length, y1 + length
            actions.append(Action(y1, x1, x2, 1))
            actions.append(Action(y2, x1, x2, -1))
            unique_x.extend([x1, x2])
        
        unique_x = sorted(set(unique_x))
        actions.sort()
        
        count = len(unique_x)
        active = [0] * (count * 4)
        coverage = [0] * (count * 4)
        
        def modify(index, left, right, start, end, val):
            if end < left or right < start:
                return
            if start <= left and right <= end:
                active[index] += val
            else:
                middle = (left + right) // 2
                modify(index * 2, left, middle, start, end, val)
                modify(index * 2 + 1, middle + 1, right, start, end, val)
            
            if active[index] > 0:
                coverage[index] = unique_x[right + 1] - unique_x[left]
            else:
                coverage[index] = 0 if left == right else coverage[index * 2] + coverage[index * 2 + 1]
        
        total_area = 0
        previous_y = actions[0].y_axis
        
        i = 0
        while i < len(actions):
            current_y = actions[i].y_axis
            height = current_y - previous_y
            x_covered = coverage[1]
            total_area += x_covered * height
            
            while i < len(actions) and actions[i].y_axis == current_y:
                left_idx = bisect_left(unique_x, actions[i].x_start)
                right_idx = bisect_left(unique_x, actions[i].x_end) - 1
                if left_idx <= right_idx:
                    modify(1, 0, count - 2, left_idx, right_idx, actions[i].kind)
                i += 1
            
            previous_y = current_y
        
        half_threshold = total_area / 2.0
        active = [0] * (count * 4)
        coverage = [0] * (count * 4)
        
        accumulated_area = 0.0
        result_y = 0.0
        previous_y = actions[0].y_axis
        found = False
        j = 0
        
        while j < len(actions) and not found:
            current_y = actions[j].y_axis
            height = current_y - previous_y
            x_length = coverage[1]
            
            if x_length > 0 and accumulated_area + x_length * height >= half_threshold:
                result_y = previous_y + (half_threshold - accumulated_area) / x_length
                found = True
                break
            
            accumulated_area += x_length * height
            
            while j < len(actions) and actions[j].y_axis == current_y:
                left_idx = bisect_left(unique_x, actions[j].x_start)
                right_idx = bisect_left(unique_x, actions[j].x_end) - 1
                if left_idx <= right_idx:
                    modify(1, 0, count - 2, left_idx, right_idx, actions[j].kind)
                j += 1
            
            previous_y = current_y
        
        return result_y if found else previous_y