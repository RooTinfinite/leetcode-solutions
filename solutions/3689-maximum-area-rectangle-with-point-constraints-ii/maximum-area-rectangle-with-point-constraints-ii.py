class Solution:
    def maxRectangleArea(self, xCoord: List[int], yCoord: List[int]) -> int:
        n = len(xCoord)
        points = sorted(zip(xCoord, yCoord))
        x_map, y_map = self.build_axis_map(points)
        # index compression
        yp = {y: idx for idx, y in enumerate(sorted(set(yCoord)))}
        st = ST(len(yp))
        ans = -1
        # lower left is (x1, y1), upper right is (x2, y2)
        for x2, y_choices in x_map.items():
            sz = len(y_choices)
            for i in range(1, sz):
                y1, y2 = y_choices[i - 1], y_choices[i]
                y1_x1 = self.get_point_on_left(y_map[y1], x2)
                y2_x1 = self.get_point_on_left(y_map[y2], x2)
                # No point on left or they are not on same line parallel to y axis
                if y1_x1 != y2_x1 or y1_x1 == -1:
                    continue
                # Point to the left of x2 on both the lines y=y1 and y=y2 is x1
                x1 = y1_x1
                x1_y1_p = bisect_left(x_map[x1], y1)
                # There is some point between y1 and y2 on line x=x1
                if x_map[x1][x1_y1_p + 1] != y2:
                    continue
                # No x between y1 and y2 should be greater than x1. (Point inside the rectangle)
                if st.query(yp[y1], yp[y2]) == x1:
                    ans = max(ans, (x2 - x1) * (y2 - y1))
            # Updating max value of x for the range y_choices
            for y in y_choices:
                st.update(yp[y], x2)
        return ans

    @staticmethod
    def get_point_on_left(x_pts: List[int], target: int) -> int:
        p = bisect_left(x_pts, target - 1)
        if x_pts[p] == target:
            p -= 1
        return x_pts[p] if p >= 0 else -1

    @staticmethod
    def build_axis_map(points: List[List[int]]) -> Tuple[Dict[int, List[int]], Dict[int, List[int]]]:
        x_map = defaultdict(list)
        y_map = defaultdict(list)
        for x, y in points:
            x_map[x].append(y)
            y_map[y].append(x)
        return x_map, y_map


class ST:
    __slots__ = ('t', 'n')
    def __init__(self, n: int):
        self.t = [0] * (4 * n)
        self.n = n

    def _update(self, v: int, tl: int, tr: int, idx: int, val: int):
        if tl == tr:
            self.t[v] = val
        else:
            tm = (tl + tr) // 2
            if idx <= tm:
                self._update(v * 2, tl, tm, idx, val)
            else:
                self._update(v * 2 + 1, tm + 1, tr, idx, val)
            self.t[v] = max(self.t[v * 2], self.t[v * 2 + 1])

    def _query(self, v: int, tl: int, tr: int, l: int, r: int) -> int:
        if l > r:
            return 0
        if tl == l and tr == r:
            return self.t[v]
        tm = (tl + tr) // 2
        return max(
            self._query(v * 2, tl, tm, l, min(r, tm)),
            self._query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
        )

    def update(self, idx: int, val: int):
        self._update(1, 0, self.n - 1, idx, val)

    def query(self, l: int, r: int) -> int:
        return self._query(1, 0, self.n - 1, l, r)