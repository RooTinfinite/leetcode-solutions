class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        if n == 1:
            return 0
        edges = build_edges(points)
        return kruskal(edges, n)

def kruskal(edges: List[Tuple[int, int, int]], n: int):
    uf = UnionFind(n)
    return sum(cost for cost, a, b in edges if uf.union(a, b))

def build_edges(points: List[List[int]]):
    edges = []
    n = len(points)

    def intercept(id: int):
        x, y = points[id]
        return y - x, x

    for iteration in range(4):
        if iteration & 1:
            for point in points:
                point.reverse()
        elif iteration:
            for point in points:
                point[0] = -point[0]
        
        sorted_by_x = sorted(enumerate(points), key=itemgetter(1), reverse=True)
        sorted_by_intercept = sorted(range(n), key=intercept, reverse=True)
        rank_lookup = [0] * n
        for rank, point_id in enumerate(sorted_by_intercept, 1):
            rank_lookup[point_id] = rank
        
        bit = BIT(n)
        for point_id, (x, y) in sorted_by_x:
            rank = rank_lookup[point_id]
            sw_most = bit.query(rank)
            if sw_most != -1:
                sw_x, sw_y = points[sw_most]
                dist = abs(x - sw_x) + abs(y - sw_y)
                edges.append((dist, point_id, sw_most))
            bit.update(rank, x + y, point_id)
    edges.sort()
    return edges

class BIT:
    def __init__(self, n: int):
        self.num = [(inf, -1) for _ in range(n + 1)]
        self.n = n
    
    def query(self, max_rank: int):
        min_dist = inf
        res = -1
        while max_rank:
            curr_dist, curr_num = self.num[max_rank]
            if curr_dist < min_dist:
                min_dist = curr_dist
                res = curr_num
            max_rank -= max_rank & -max_rank
        return res

    def update(self, rank: int, dist: int, id: int):
        while rank <= self.n:
            curr_dist, _ = self.num[rank]
            if dist >= curr_dist:
                break
            self.num[rank] = dist, id
            rank += rank & -rank

class UnionFind:
    def __init__(self, n: int):
        self.root_lookup = list(range(n))
        self.rank_lookup = [1] * n
    
    def find(self, num: int):
        root = self.root_lookup[num]
        path = [num]
        while root != self.root_lookup[root]:
            path.append(root)
            root = self.root_lookup[root]
        for node in path:
            self.root_lookup[node] = root
        return root

    def union(self, num1: int, num2: int):
        root1, root2 = self.find(num1), self.find(num2)
        if root1 == root2:
            return False
        rank1, rank2 = self.rank_lookup[root1], self.rank_lookup[root2]
        if rank1 < rank2:
            root1, root2 = root2, root1
            rank2 = rank1
        self.root_lookup[root2] = root1
        self.rank_lookup[root1] += rank2
        return True