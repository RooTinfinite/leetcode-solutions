var minReorder = function (n, connections) {
    let adj = [], grid = [], vis = [], len = connections.length;
    for (let i = 0; i < n; i++) {
        grid.push([]);
        vis[i] = 0;
    }
    for (let i = 0; i < len; i++) {
        let src = connections[i][0];
        let dest = connections[i][1];
        grid[src].push(-1 * dest);
        grid[dest].push(src);
    }
    console.log(grid);
    return solve(grid, 0, vis);
};
function solve(grid, val, vis) {
    if (vis[val] === 1) {
        return 0;
    }
    let ans = 0;
    vis[val] = 1;
    for (let i = 0; i < grid[val].length; i++) {
        let ele = grid[val][i];
        if (vis[Math.abs(ele)] == 1) {
            continue;
        }
        if (ele < 0) {
            ans += 1;
        }
        ans += solve(grid, Math.abs(ele), vis);
    }
    return ans;
}