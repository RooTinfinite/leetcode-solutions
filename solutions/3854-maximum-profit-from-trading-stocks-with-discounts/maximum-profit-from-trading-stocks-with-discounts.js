var maxProfit = function (n, present, future, hierarchy, budget) {
    const g = Array.from({ length: n }, () => []);

    for (const e of hierarchy) {
        g[e[0] - 1].push(e[1] - 1);
    }

    const dfs = (u) => {
        const cost = present[u];
        const dCost = Math.floor(present[u] / 2); // discounted cost

        // dp[u][state][budget]
        // state: 0 = not purchasing parent node, 1 = purchasing parent node
        const dp0 = new Array(budget + 1).fill(0);
        const dp1 = new Array(budget + 1).fill(0);

        // subProfit[state][budget]
        // state = 0: discount not available, state = 1: discount available
        const subProfit0 = Array(budget + 1).fill(0);
        const subProfit1 = Array(budget + 1).fill(0);

        let uSize = cost;

        for (const v of g[u]) {
            const [subDp0, subDp1, vSize] = dfs(v);
            uSize += vSize;

            for (let i = budget; i >= 0; i--) {
                for (let sub = 0; sub <= Math.min(vSize, i); sub++) {
                    subProfit0[i] = Math.max(
                        subProfit0[i],
                        subProfit0[i - sub] + subDp0[sub],
                    );
                    subProfit1[i] = Math.max(
                        subProfit1[i],
                        subProfit1[i - sub] + subDp1[sub],
                    );
                }
            }
        }

        for (let i = 0; i <= budget; i++) {
            dp0[i] = dp1[i] = subProfit0[i];

            if (i >= dCost) {
                dp1[i] = Math.max(
                    subProfit0[i],
                    subProfit1[i - dCost] + future[u] - dCost,
                );
            }

            if (i >= cost) {
                dp0[i] = Math.max(
                    subProfit0[i],
                    subProfit1[i - cost] + future[u] - cost,
                );
            }
        }

        return [dp0, dp1, uSize];
    };

    return dfs(0)[0][budget];
};