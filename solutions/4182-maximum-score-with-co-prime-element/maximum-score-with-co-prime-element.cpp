class Solution {
public:
    const int MAXN = 100001;
    vector<int> spf;
    void sieve() {
        spf.resize(MAXN);
        for (int i = 0; i < MAXN; i++) {
            spf[i] = i;
        }
        for (int i = 2; 1LL * i * i < MAXN; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j < MAXN; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }
    vector<int> primes;
    void distinctPrimes(int x) {
        primes.clear();
        while (x > 1) {
            int s = spf[x];
            primes.push_back(s);
            while (x % s == 0) {
                x /= s;
            }
        }
    }
    int countUsingIncExc(int v, const vector<int>& precomputeUnion) {
        distinctPrimes(v);
        int k = primes.size();
        int clash = 0;
        for (int mask = 1; mask < (1 << k); mask++) {
            int d = 1, bits = 0;
            for (int b = 0; b < k; b++) {
                if (mask & (1 << b)) {
                    d *= primes[b];
                    bits++;
                }
            }
            clash += (bits & 1) ? precomputeUnion[d] : -precomputeUnion[d];
        }
        return clash;
    }
    int maxScore(vector<int>& nums, int maxVal) {
        sieve();
        unordered_map<int, bool> isPresent;
        vector<int> precomputeUnion(MAXN);
        for (const int& x : nums) {
            isPresent[x] = true;
            distinctPrimes(x);
            int k = primes.size();
            for (int mask = 1; mask < (1 << k); mask++) {
                int d = 1;
                for (int b = 0; b < k; b++) {
                    if (mask & (1 << b)) {
                        d *= primes[b];
                    }
                }
                precomputeUnion[d]++;
            }
        }
        int score = 0;
        // case-1 : (1 <= selectedValue <= maxVal)
        for (int selectedValue = 1; selectedValue <= maxVal; selectedValue++) {
            int count = countUsingIncExc(selectedValue, precomputeUnion);
            int modificationCost = 0;
            if (isPresent.count(selectedValue)) {
                modificationCost = (selectedValue == 1) ? 0 : count - 1;
            } else {
                modificationCost = (count == 0) ? 1 : count;
            }
            score = max(score, selectedValue - modificationCost);
        }
        // case-2 : (selectedValue > maxVal)
        for (const int& selectedValue : nums) {
            if (selectedValue <= maxVal) {
                continue;
            }
            int count = countUsingIncExc(selectedValue, precomputeUnion);
            int modificationCost = count - 1;
            score = max(score, selectedValue - modificationCost);
        }
        return score;
    }
};