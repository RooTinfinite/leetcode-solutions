typedef struct {
    int size;
    long long* _tree1;
    long long* _tree2;
} BIT;

BIT* createBIT(int n) {
    BIT* bit = (BIT*)malloc(sizeof(BIT));
    bit->size = n;
    bit->_tree1 = (long long*)calloc(n + 2, sizeof(long long));
    bit->_tree2 = (long long*)calloc(n + 2, sizeof(long long));
    return bit;
}

void freeBIT(BIT* bit) {
    free(bit->_tree1);
    free(bit->_tree2);
    free(bit);
}

int _lowbit(int index) { return index & -index; }

void _add(BIT* bit, int index, int delta) {
    index += 1;
    long long rawIndex = index;
    while (index <= bit->size) {
        bit->_tree1[index] += delta;
        bit->_tree2[index] += rawIndex * delta;
        index += _lowbit(index);
    }
}

long long _query(BIT* bit, int index) {
    index += 1;
    long long rawIndex = index + 1;
    if (index > bit->size) {
        index = bit->size;
    }
    long long res = 0;
    while (index > 0) {
        res += rawIndex * bit->_tree1[index] - bit->_tree2[index];
        index -= _lowbit(index);
    }
    return res;
}

void add(BIT* bit, int left, int right, int delta) {
    _add(bit, left, delta);
    _add(bit, right + 1, -delta);
}

long long query(BIT* bit, int left, int right) {
    return _query(bit, right) - _query(bit, left - 1);
}

int sumCounts(int* A, int ASize) {
    int n = ASize;
    long long res = 0, cur = 0;
    BIT* bit = createBIT(n + 10);

    int seen[100005];
    memset(seen, -1, sizeof(seen));
    long long mod = 1000000007;

    for (int i = 0; i < n; i++) {
        int a = A[i];
        int j = seen[a] + 1;
        long long q = query(bit, j, i);
        cur = (cur + q * 2 + i - j + 1) % mod;
        res = (res + cur) % mod;
        add(bit, j, i, 1);
        seen[a] = i;
    }

    freeBIT(bit);
    return (int)res;
}