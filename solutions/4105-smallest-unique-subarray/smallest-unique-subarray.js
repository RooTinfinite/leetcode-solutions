var smallestUniqueSubarray = function (nums) {
    const n = nums.length;

    let sa = new Int32Array(n);
    let rank = Int32Array.from(nums);
    let nextRank = new Int32Array(n);

    for (let i = 0; i < n; ++i) {
        sa[i] = i;
    }

    // Construct the sorted suffix array by doubling
    let maxRank = 0;
    for (const num of nums) {
        maxRank = Math.max(maxRank, num);
    }

    let temp = new Int32Array(n);
    const cnt = new Int32Array(Math.max(n + 1, maxRank + 2));

    const countingSort = (getKey) => {
        cnt.fill(0, 0, maxRank + 2);

        for (const i of sa) {
            ++cnt[getKey(i)];
        }

        for (let i = 1; i <= maxRank + 1; ++i) {
            cnt[i] += cnt[i - 1];
        }

        for (let p = n - 1; p >= 0; --p) {
            const i = sa[p];
            temp[--cnt[getKey(i)]] = i;
        }

        [sa, temp] = [temp, sa];
    };

    for (let k = 1; k < n; k *= 2) {
        // Sort by the second key, then stably sort by the first key
        countingSort((i) => (i + k < n ? rank[i + k] + 1 : 0));
        countingSort((i) => rank[i] + 1);

        nextRank[sa[0]] = 0;

        // Assign ranks to the newly sorted suffixes
        for (let i = 1; i < n; ++i) {
            const x = sa[i - 1],
                y = sa[i];
            const rx = x + k < n ? rank[x + k] : -1;
            const ry = y + k < n ? rank[y + k] : -1;

            nextRank[y] =
                nextRank[x] + (rank[x] !== rank[y] || rx !== ry ? 1 : 0);
        }

        [rank, nextRank] = [nextRank, rank];
        maxRank = rank[sa[n - 1]];

        // All n suffixes have distinct ranks, so sorting is complete
        if (maxRank === n - 1) {
            break;
        }
    }

    // Construct LCP using Kasai's algorithm
    const pos = new Int32Array(n);
    const lcp = new Int32Array(n);
    for (let i = 0; i < n; ++i) {
        pos[sa[i]] = i;
    }

    let h = 0;
    for (let i = 0; i < n; ++i) {
        if (pos[i] === 0) {
            h = 0;
            continue;
        }

        const j = sa[pos[i] - 1];
        while (i + h < n && j + h < n && nums[i + h] === nums[j + h]) {
            ++h;
        }

        lcp[pos[i]] = h;

        if (h > 0) {
            --h;
        }
    }

    let answer = n;
    for (let i = 0; i < n; ++i) {
        const next = i + 1 < n ? lcp[i + 1] : 0;

        const need = Math.max(lcp[i], next) + 1;
        if (sa[i] + need <= n) {
            answer = Math.min(answer, need);
        }
    }

    return answer;
};