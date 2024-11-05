class Solution:
    def minReorder(self, n, connections):
        grid = [[] for _ in range(n)]
        vis = [False] * n

        for src, dest in connections:
            grid[src].append(-dest)
            grid[dest].append(src)

        return self.solve(grid, 0, vis)

    def solve(self, grid, val, vis):
        if vis[val]:
            return 0
        ans = 0
        vis[val] = True
        for ele in grid[val]:
            if vis[abs(ele)]:
                continue
            if ele < 0:
                ans += 1
            ans += self.solve(grid, abs(ele), vis)
        return ans

# Example usage:
sol = Solution()
n = 6
connections = [[0, 1], [1, 3], [2, 3], [4, 0], [4, 5]]
print(sol.minReorder(n, connections))