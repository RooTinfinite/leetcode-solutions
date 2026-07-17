var gcdValues = function (nums, queries) {
    const m = Math.max(...nums);
    const cnt = new Array(m + 1).fill(0);
    for (const num of nums) {
        cnt[num]++;
    }
    for (let i = 1; i <= m; i++) {
        for (let j = i * 2; j <= m; j += i) {
            cnt[i] += cnt[j];
        }
    }
    for (let i = 1; i <= m; i++) {
        cnt[i] = Math.floor((cnt[i] * (cnt[i] - 1)) / 2);
    }
    for (let i = m; i >= 1; i--) {
        for (let j = i * 2; j <= m; j += i) {
            cnt[i] -= cnt[j];
        }
    }
    for (let i = 1; i <= m; i++) {
        cnt[i] += cnt[i - 1];
    }
    const ans = [];
    for (let q of queries) {
        q++;
        let left = 1,
            right = m;
        while (left < right) {
            const mid = Math.floor((left + right) / 2);
            if (cnt[mid] >= q) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        ans.push(left);
    }
    return ans;
};