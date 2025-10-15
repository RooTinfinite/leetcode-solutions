class Solution {
public:
    vector<int> subarrayMajority(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), qn = queries.size();

        struct Query {
            int l, r, threshold, idx;
        };

        vector<Query> queriesVect(qn);
        vector<int> res(qn);
        for(int i = 0; i < qn; i++) {
            queriesVect[i].l = queries[i][0];
            queriesVect[i].r = queries[i][1];
            queriesVect[i].threshold = queries[i][2];
            queriesVect[i].idx = i;
        }

        unordered_map<int, int> freqMap(n);
        vector<set<int>> freqs(n + 1);
        int maxFreq = 0;

        int block_size = max<int>(1, n / sqrt(qn));
        sort(queriesVect.begin(), queriesVect.end(), [&](auto& a, auto& b) -> bool {
            return make_pair(a.l / block_size, (a.l / block_size & 1) ? -a.r : a.r)
                < make_pair(b.l / block_size, (a.l / block_size & 1) ? -b.r : b.r);
        });

        auto add = [&](int idx) -> void {
            int num = nums[idx];
            freqs[freqMap[num]].erase(num);
            freqs[++freqMap[num]].insert(num);
            if(freqMap[num] > maxFreq) maxFreq = freqMap[num];
        };

        auto remove = [&](int idx) -> void {
            int num = nums[idx];
            freqs[freqMap[num]].erase(num);
            if(int resFreq = --freqMap[num]; resFreq > 0)
                freqs[resFreq].insert(num);

            if(maxFreq > 0 && freqs[maxFreq].empty()) maxFreq--;
        };

        auto get_answer = [&](const Query& query) -> int {
            if(maxFreq < query.threshold) return -1;
            return *freqs[maxFreq].begin();
        };
        
        int cur_l = 0;
        int cur_r = -1;
        
        for (Query& q : queriesVect) {
            while (cur_r < q.r) {
                cur_r++;
                add(cur_r);
            }
            while (cur_l > q.l) {
                cur_l--;
                add(cur_l);
            }
            while (cur_r > q.r) {
                remove(cur_r);
                cur_r--;
            }
            while (cur_l < q.l) {
                remove(cur_l);
                cur_l++;
            }
            res[q.idx] = get_answer(q);
        }
        return res;
    }
};