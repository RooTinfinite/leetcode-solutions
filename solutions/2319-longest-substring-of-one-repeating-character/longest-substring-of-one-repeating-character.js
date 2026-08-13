var longestRepeating = function (s, queryCharacters, queryIndices) {
    const n = s.length;
    const pre = new Array(4 * n).fill(0);
    const suf = new Array(4 * n).fill(0);
    const maxLen = new Array(4 * n).fill(0);
    const leftChar = new Array(4 * n).fill("");
    const rightChar = new Array(4 * n).fill("");

    const pushUp = (u, l, r) => {
        const mid = (l + r) >> 1;
        const leftLen = mid - l + 1,
            rightLen = r - mid;
        const left = u << 1,
            right = (u << 1) | 1;
        leftChar[u] = leftChar[left];
        rightChar[u] = rightChar[right];
        pre[u] = pre[left];
        if (pre[left] === leftLen && rightChar[left] === leftChar[right]) {
            pre[u] = pre[left] + pre[right];
        }
        suf[u] = suf[right];
        if (suf[right] === rightLen && rightChar[left] === leftChar[right]) {
            suf[u] = suf[right] + suf[left];
        }
        maxLen[u] = Math.max(maxLen[left], maxLen[right]);
        if (rightChar[left] === leftChar[right]) {
            maxLen[u] = Math.max(maxLen[u], suf[left] + pre[right]);
        }
    };

    const build = (u, l, r) => {
        if (l === r) {
            pre[u] = 1;
            suf[u] = 1;
            maxLen[u] = 1;
            leftChar[u] = s[l];
            rightChar[u] = s[l];
            return;
        }
        const mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build((u << 1) | 1, mid + 1, r);
        pushUp(u, l, r);
    };

    const update = (u, l, r, pos, ch) => {
        if (l === r) {
            leftChar[u] = ch;
            rightChar[u] = ch;
            return;
        }
        const mid = (l + r) >> 1;
        if (pos <= mid) {
            update(u << 1, l, mid, pos, ch);
        } else {
            update((u << 1) | 1, mid + 1, r, pos, ch);
        }
        pushUp(u, l, r);
    };

    build(1, 0, n - 1);
    const k = queryIndices.length;
    const ans = new Array(k);
    for (let i = 0; i < k; i++) {
        update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
        ans[i] = maxLen[1];
    }
    return ans;
};