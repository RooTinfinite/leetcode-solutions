var findSafeWalk = function (grid, health) {
    const m = grid.length,
        n = grid[0].length;
    const dirs = [
        [0, 1],
        [0, -1],
        [1, 0],
        [-1, 0],
    ];
    const dis = Array.from({ length: m }, () => new Array(n).fill(Infinity));

    const q = new Deque();
    q.pushFront([0, 0]);
    dis[0][0] = grid[0][0];

    while (!q.isEmpty()) {
        const [cx, cy] = q.popFront();
        // the first time it leaves the queue, the shortest distance is guaranteed
        if (cx === m - 1 && cy === n - 1) {
            return true;
        }

        for (const [dx, dy] of dirs) {
            const nx = cx + dx,
                ny = cy + dy;
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                continue;
            }
            const cost = dis[cx][cy] + grid[nx][ny];
            // pruning: the new distance does not meet health requirements
            if (cost >= health) {
                continue;
            }

            if (cost < dis[nx][ny]) {
                dis[nx][ny] = cost;
                if (grid[nx][ny] === 0) {
                    q.pushFront([nx, ny]);
                } else {
                    q.pushBack([nx, ny]);
                }
            }
        }
    }

    return false;
};