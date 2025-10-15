vector<bool> isPrime (1e6 + 1, true);

class Solution {
public:
    void fill () {
        isPrime [0] = isPrime [1] = false;
        for (int i = 2; i * i <= 1e6; ++i) {
            if (isPrime [i]) {
                for (int j = i * i; j <= 1e6; j += i)
                    isPrime [j] = false;
            }
        }
    }

    int minJumps(vector<int>& nums) {
        if (isPrime[0]) fill();
        int n = nums.size(), maxi = *ranges::max_element(nums);
        unordered_map <int,vector <int>> mp;
        for (int i = 0; i < n; i++) mp[nums[i]].push_back(i);
        
        vector <int> dist (n, -1);
        queue <int> qu;
        qu.push(0); dist[0] = 0;
        unordered_set <int> used;

        while (qu.empty() == false) {
            int node = qu.front();
            qu.pop();

            if (node - 1 >= 0 && dist[node-1] == -1) {
                qu.push(node-1);
                dist[node-1] = dist[node] + 1;
            }
            if (node + 1 < n && dist[node+1] == -1) {
                qu.push(node+1);
                dist[node+1] = dist[node] + 1;
            }

            if (isPrime[nums[node]] == false || used.contains(nums[node])) continue;

            for (int tar = nums[node]; tar <= maxi; tar += nums[node]) {
                if (mp.contains(tar) == false) continue;
                for (auto it : mp[tar]) {
                    if (dist[it] != -1) continue;
                    qu.push(it);
                    if (it == n-1) return dist[node] + 1;
                    dist[it] = dist[node] + 1;
                }
            }

            used.insert(nums[node]);
        }

        return dist.back();
    }
};