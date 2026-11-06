typedef struct {
    int id;
    int time;
} LogEntry;

static int cmp_log(const void* a, const void* b) {
    const LogEntry* la = (const LogEntry*)a;
    const LogEntry* lb = (const LogEntry*)b;
    if (la->time < lb->time) {
        return -1;
    }
    if (la->time > lb->time) {
        return 1;
    }
    return 0;
}

typedef struct {
    int idx;
    int q;
} QueryEntry;

static int cmp_query(const void* a, const void* b) {
    const QueryEntry* qa = (const QueryEntry*)a;
    const QueryEntry* qb = (const QueryEntry*)b;
    if (qa->q < qb->q) {
        return -1;
    }
    if (qa->q > qb->q) {
        return 1;
    }
    return 0;
}

int* countServers(int n, int** logs, int logsSize, int* logsColSize, int x,
                  int* queries, int queriesSize, int* returnSize) {
    LogEntry* entries =
        (LogEntry*)malloc(sizeof(LogEntry) * (logsSize > 0 ? logsSize : 1));
    for (int i = 0; i < logsSize; ++i) {
        entries[i].id = logs[i][0];
        entries[i].time = logs[i][1];
    }
    qsort(entries, logsSize, sizeof(LogEntry), cmp_log);

    QueryEntry* qEntries =
        (QueryEntry*)malloc(sizeof(QueryEntry) * queriesSize);
    for (int i = 0; i < queriesSize; ++i) {
        qEntries[i].idx = i;
        qEntries[i].q = queries[i];
    }
    qsort(qEntries, queriesSize, sizeof(QueryEntry), cmp_query);

    int* ans = (int*)malloc(sizeof(int) * queriesSize);
    int* cnt = (int*)calloc(n + 1, sizeof(int));
    int left = 0, right = 0, active = 0;

    for (int k = 0; k < queriesSize; ++k) {
        int i = qEntries[k].idx;
        int q = qEntries[k].q;

        while (right < logsSize && entries[right].time <= q) {
            int id = entries[right++].id;
            if (cnt[id]++ == 0) ++active;
        }
        while (left < right && entries[left].time < q - x) {
            int id = entries[left++].id;
            if (--cnt[id] == 0) --active;
        }

        ans[i] = n - active;
    }

    free(entries);
    free(qEntries);
    free(cnt);

    *returnSize = queriesSize;
    return ans;
}