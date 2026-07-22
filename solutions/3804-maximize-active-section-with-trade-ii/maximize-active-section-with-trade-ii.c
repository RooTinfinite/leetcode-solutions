int bruteForce(char* s, int l, int r) {
    int i = l;
    int best = 0;
    int prev = INT_MIN;

    while (i <= r) {
        int start = i;
        while (i <= r && s[i] == s[start]) {
            i++;
        }
        if (s[start] == '0') {
            int cur = i - start;
            if (prev != INT_MIN && prev + cur > best) {
                best = prev + cur;
            }
            prev = cur;
        }
    }
    return best;
}

int cmp(const void* a, const void* b) {
    int* qa = *(int**)a;
    int* qb = *(int**)b;
    if (qa[0] != qb[0]) {
        return qa[0] - qb[0];
    }
    return qa[2] - qb[2];
}

int* maxActiveSectionsAfterTrade(char* s, int** queries, int queriesSize,
                                 int* queriesColSize, int* returnSize) {
    int n = strlen(s), m = queriesSize;
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') cnt1++;
    }
    // left[i]: represents the length of the continuous block ending at position
    // i, which is the same as s[i]
    int* left = (int*)malloc(n * sizeof(int));
    // right[i]: represents the length of the continuous block starting at
    // position i with the same value as s[i]
    int* right = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        if (i > 0 && s[i - 1] == s[i]) {
            left[i] = left[i - 1] + 1;
        } else {
            left[i] = 1;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i < n - 1 && s[i + 1] == s[i]) {
            right[i] = right[i + 1] + 1;
        } else {
            right[i] = 1;
        }
    }

    int* ans = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        ans[i] = -1;
    }
    int block_size = (int)sqrt(n);

    // query with length greater than block length
    int** longQueries = (int**)malloc(m * sizeof(int*));
    int longCnt = 0;

    for (int i = 0; i < m; i++) {
        int l = queries[i][0], r = queries[i][1];
        if (r - l + 1 > block_size) {
            longQueries[longCnt] = (int*)malloc(4 * sizeof(int));
            longQueries[longCnt][0] = l / block_size;
            longQueries[longCnt][1] = l;
            longQueries[longCnt][2] = r;
            longQueries[longCnt][3] = i;
            longCnt++;
        } else {
            // queries shorter than block length, brute-force calculation
            ans[i] = cnt1 + bruteForce(s, l, r);
        }
    }

    // sort by the ID of the block where the left endpoint is located as the
    // first keyword, and by the right endpoint as the second keyword
    qsort(longQueries, longCnt, sizeof(int*), cmp);
    // use an array to simulate a double-ended queue, expanding from the middle
    // to avoid frequent memory allocation
    int* subZeroBlocks = (int*)malloc(n * sizeof(int));
    int head = n / 2, tail = n / 2;
    int L = 0, R = 0, bestGain = 0;

    for (int i = 0; i < longCnt; i++) {
        int bid = longQueries[i][0];
        int l = longQueries[i][1];
        int r = longQueries[i][2];
        int qid = longQueries[i][3];

        if (i == 0 || bid > longQueries[i - 1][0]) {
            // traverse to a new block, perform initialization operations
            L = (bid + 1) * block_size -
                1;  // L is initialized to the right endpoint of the block
            R = (bid + 1) * block_size;  // R is initialized to the left
                                         // endpoint of the next block
            head = tail = n / 2;
            bestGain = 0;
        }

        while (R <= r) {
            int sz = right[R];
            if (r - R + 1 < sz) {
                sz = r - R + 1;
            }
            if (s[R] == '0') {
                if (tail > head && R > 0 && s[R - 1] == '0') {
                    subZeroBlocks[tail - 1] += sz;
                } else {
                    subZeroBlocks[tail] = sz;
                    tail++;
                }
                if (tail - head >= 2) {
                    int val = subZeroBlocks[tail - 1] + subZeroBlocks[tail - 2];
                    if (val > bestGain) {
                        bestGain = val;
                    }
                }
            }
            R += sz;
        }

        // before moving the left endpoint L, backup the value of bestGain
        int tmp_bestGain = bestGain;
        // value of the first element of subZeroBlocks before moving the left
        // endpoint
        int tmp_firstValue = -1;
        if (tail > head) {
            tmp_firstValue = subZeroBlocks[head];
        }
        // the number of digits added from the left during the process of
        // recording the movement of the left endpoint L
        int cnt = 0;

        while (L >= l) {
            int sz = left[L];
            if (L - l + 1 < sz) {
                sz = L - l + 1;
            }
            if (s[L] == '0') {
                if (tail > head && L + 1 < n && s[L + 1] == '0') {
                    subZeroBlocks[head] += sz;
                } else {
                    head--;
                    subZeroBlocks[head] = sz;
                    cnt++;
                }
                if (tail - head >= 2) {
                    int val = subZeroBlocks[head] + subZeroBlocks[head + 1];
                    if (val > bestGain) {
                        bestGain = val;
                    }
                }
            }
            L -= sz;
        }

        // answering inquiries
        ans[qid] = bestGain + cnt1;
        // restore left endpoint L
        L = (bid + 1) * block_size - 1;
        // restore bestGain
        bestGain = tmp_bestGain;
        // restore subZeroBlocks
        head += cnt;
        if (tmp_firstValue != -1 && head < tail) {
            subZeroBlocks[head] = tmp_firstValue;
        }
    }

    free(left);
    free(right);
    free(subZeroBlocks);
    for (int i = 0; i < longCnt; i++) {
        free(longQueries[i]);
    }
    free(longQueries);
    *returnSize = m;
    return ans;
}