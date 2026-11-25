int smallestUniqueSubarray(int* nums, int n) {
    int* sa = (int*)malloc(sizeof(int) * n);
    int* rank = (int*)malloc(sizeof(int) * n);
    int* nextRank = (int*)malloc(sizeof(int) * n);
    int* temp = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; ++i) {
        sa[i] = i;
        rank[i] = nums[i];
    }

    int maxRank = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] > maxRank) {
            maxRank = nums[i];
        }
    }

    int cntSize = n + 1 > maxRank + 2 ? n + 1 : maxRank + 2;
    int* cnt = (int*)malloc(sizeof(int) * cntSize);

    for (int k = 1; k < n; k <<= 1) {
        // First pass: counting sort by the second key (rank[i+k] or -1)
        memset(cnt, 0, sizeof(int) * cntSize);
        for (int p = 0; p < n; ++p) {
            int i = sa[p];
            int key = (i + k < n ? rank[i + k] : -1) + 1;
            ++cnt[key];
        }
        for (int i = 1; i <= maxRank + 1; ++i) {
            cnt[i] += cnt[i - 1];
        }
        for (int p = n - 1; p >= 0; --p) {
            int i = sa[p];
            int key = (i + k < n ? rank[i + k] : -1) + 1;
            temp[--cnt[key]] = i;
        }
        int* sw = sa;
        sa = temp;
        temp = sw;

        // Second pass: stable sort by the first key rank[i]
        memset(cnt, 0, sizeof(int) * cntSize);
        for (int p = 0; p < n; ++p) {
            int i = sa[p];
            int key = rank[i] + 1;
            ++cnt[key];
        }
        for (int i = 1; i <= maxRank + 1; ++i) {
            cnt[i] += cnt[i - 1];
        }
        for (int p = n - 1; p >= 0; --p) {
            int i = sa[p];
            int key = rank[i] + 1;
            temp[--cnt[key]] = i;
        }
        sw = sa;
        sa = temp;
        temp = sw;

        nextRank[sa[0]] = 0;
        for (int i = 1; i < n; ++i) {
            int a = sa[i - 1], b = sa[i];
            int ax = rank[a], ay = (a + k < n ? rank[a + k] : -1);
            int bx = rank[b], by = (b + k < n ? rank[b + k] : -1);
            nextRank[b] = nextRank[a] + ((ax != bx || ay != by) ? 1 : 0);
        }

        sw = rank;
        rank = nextRank;
        nextRank = sw;
        maxRank = rank[sa[n - 1]];

        if (maxRank == n - 1) {
            break;
        }
    }

    // Kasai LCP
    int* pos = (int*)calloc(n, sizeof(int));
    int* lcp = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i) {
        pos[sa[i]] = i;
    }
    int h = 0;
    for (int i = 0; i < n; ++i) {
        if (pos[i] == 0) {
            h = 0;
            continue;
        }
        int j = sa[pos[i] - 1];
        while (i + h < n && j + h < n && nums[i + h] == nums[j + h]) {
            ++h;
        }
        lcp[pos[i]] = h;
        if (h > 0) {
            --h;
        }
    }

    int answer = n;
    for (int i = 0; i < n; ++i) {
        int nxt = (i + 1 < n ? lcp[i + 1] : 0);
        int need = (lcp[i] > nxt ? lcp[i] : nxt) + 1;
        if (sa[i] + need - 1 < n) {
            answer = answer < need ? answer : need;
        }
    }

    free(sa);
    free(rank);
    free(nextRank);
    free(temp);
    free(cnt);
    free(pos);
    free(lcp);
    return answer;
}