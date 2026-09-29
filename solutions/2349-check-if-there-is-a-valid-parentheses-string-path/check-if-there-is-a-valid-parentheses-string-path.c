#define BITSET_WORDS 4
#define MAXM 105

typedef struct {
    unsigned long long words[BITSET_WORDS];
} Bitset;

static inline void bitset_set(Bitset* bs, int pos) {
    bs->words[pos >> 6] |= 1ULL << (pos & 63);
}

static inline bool bitset_test(const Bitset* bs, int pos) {
    return (bs->words[pos >> 6] >> (pos & 63)) & 1ULL;
}

static inline void bitset_or_shift_left(Bitset* dst, const Bitset* src) {
    unsigned long long carry = 0;
    for (int w = 0; w < BITSET_WORDS; ++w) {
        unsigned long long cur = src->words[w];
        dst->words[w] |= (cur << 1) | carry;
        carry = cur >> 63;
    }
}

static inline void bitset_or_shift_right(Bitset* dst, const Bitset* src) {
    unsigned long long carry = 0;
    for (int w = BITSET_WORDS - 1; w >= 0; --w) {
        unsigned long long cur = src->words[w];
        dst->words[w] |= (cur >> 1) | carry;
        carry = cur << 63;
    }
}

bool hasValidPath(char** grid, int gridSize, int* gridColSize) {
    const int n = gridSize;
    const int m = gridColSize[0];
    const int pathLen = n + m - 1;

    if (pathLen % 2 == 1) {
        return false;
    }
    if (grid[0][0] != '(' || grid[n - 1][m - 1] != ')') {
        return false;
    }
    Bitset(*dp)[MAXM] = calloc(n * MAXM, sizeof(Bitset));
    bitset_set(&dp[0][0], 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            const int change = grid[i][j] == '(' ? 1 : -1;
            if (i > 0) {
                if (change == 1) {
                    bitset_or_shift_left(&dp[i][j], &dp[i - 1][j]);
                } else {
                    bitset_or_shift_right(&dp[i][j], &dp[i - 1][j]);
                }
            }

            if (j > 0) {
                if (change == 1) {
                    bitset_or_shift_left(&dp[i][j], &dp[i][j - 1]);
                } else {
                    bitset_or_shift_right(&dp[i][j], &dp[i][j - 1]);
                }
            }
        }
    }

    bool result = bitset_test(&dp[n - 1][m - 1], 0);
    free(dp);
    return result;
}