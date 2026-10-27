class Solution {
    vector<array<int, 10>> child;   // trie over 'a'..'j': at most 10 children per node
    vector<int> rankAt;             // rank of the word that ends at a node, or -1
    long long total = 0;

    // lesson 2, unchanged: inter for two sorted blocks, 'earlier' read before 'later'
    static long long countBetween(const vector<int>& earlier, const vector<int>& later) {
        long long inv = 0;
        for (int y : later)
            inv += earlier.end() - upper_bound(earlier.begin(), earlier.end(), y);
        return inv;
    }

    // lesson 2, unchanged: merge two sorted lists with two pointers
    static vector<int> mergeSorted(const vector<int>& a, const vector<int>& b) {
        vector<int> out;
        merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(out));
        return out;
    }

    // cost[a][b] = inter inversions between blocks a and b when a is read first
    static vector<vector<long long>> costTable(const vector<vector<int>>& blocks) {
        int k = blocks.size();
        vector<vector<long long>> cost(k, vector<long long>(k, 0));
        for (int a = 0; a < k; a++)
            for (int b = a + 1; b < k; b++) {
                cost[a][b] = countBetween(blocks[a], blocks[b]);
                cost[b][a] = (long long)blocks[a].size() * blocks[b].size() - cost[a][b];  // other order
            }
        return cost;
    }

    // after[s][mask] = inversions block s adds when it is read after every block in mask
    static vector<vector<long long>> afterTable(const vector<vector<long long>>& cost) {
        int k = cost.size();
        vector<vector<long long>> after(k, vector<long long>(1 << k, 0));   // empty set adds 0
        for (int s = 0; s < k; s++)
            for (int j = 0; j < k; j++)                    // add block j to every set built so far
                for (int mask = 0; mask < (1 << j); mask++)                 // sets of blocks 0 .. j-1
                    after[s][mask | 1 << j] = after[s][mask] + cost[j][s];   // same set plus j
        return after;
    }

    // the fewest inter inversions over every order of the blocks: the chain of lesson 1,
    // built size by size, but the state is only the set (the end is not needed)
    static long long bestOrder(const vector<vector<long long>>& cost) {
        int k = cost.size(), full = (1 << k) - 1;
        vector<vector<long long>> after = afterTable(cost);
        vector<long long> dp(full + 1, LLONG_MAX);
        dp[0] = 0;                                         // nothing placed yet
        for (int mask = 1; mask <= full; mask++)           // smaller sets come first
            for (int s = 0; s < k; s++) {
                if (!(mask >> s & 1)) continue;            // s = the block placed last
                int rest = mask ^ (1 << s);                // the set before s was added
                dp[mask] = min(dp[mask], dp[rest] + after[s][rest]);
            }
        return dp[full];
    }

    // lesson 2's solve: intra by recursion, forced at the word, but inter now comes
    // from the best order instead of the given one
    vector<int> solve(int u) {
        vector<vector<int>> blocks;
        for (int c = 0; c < 10; c++)
            if (child[u][c] != -1) blocks.push_back(solve(child[u][c]));   // intra: leap of faith
        if (blocks.size() >= 2) total += bestOrder(costTable(blocks));     // inter: best order

        vector<int> seen;                                  // everything below u, sorted
        for (const vector<int>& b : blocks) seen = mergeSorted(seen, b);
        if (rankAt[u] != -1) {                             // forced: u is a word, read first
            auto pos = lower_bound(seen.begin(), seen.end(), rankAt[u]);
            total += pos - seen.begin();
            seen.insert(pos, rankAt[u]);
        }
        return seen;                                       // hand the sorted list to the parent
    }

public:
    int minInversions(vector<string>& words, vector<int>& target) {
        int n = words.size();
        vector<int> rank(n);                               // step 1: a word is its rank
        for (int p = 0; p < n; p++) rank[target[p]] = p;

        child.assign(1, {});                               // step 2: the trie
        child[0].fill(-1);
        rankAt.assign(1, -1);
        for (int i = 0; i < n; i++) {
            int u = 0;
            for (char ch : words[i]) {
                int c = ch - 'a';
                if (child[u][c] == -1) {
                    child[u][c] = child.size();
                    child.push_back({});
                    child.back().fill(-1);
                    rankAt.push_back(-1);
                }
                u = child[u][c];
            }
            rankAt[u] = rank[i];
        }

        total = 0;
        solve(0);
        return (int)total;
    }
};