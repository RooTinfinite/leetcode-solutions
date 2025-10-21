class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int n = arrivals.size();
        if (n == 0) return 0;
        
        unordered_map<int,int> hash; // type -> count in current window
        vector<int> kept(n, 0);      // track kept items
        int dis = 0;
        
        for (int i = 0; i < n; i++) {
            int idx = i - w;
            if (idx >= 0 && kept[idx]) {
                hash[arrivals[idx]]--;
            }
            
            int t = arrivals[i];
            if (hash[t] < m) {
                kept[i] = 1;
                hash[t]++;
            } else {
                dis++;
            }
        }
        return dis;
    }
};