class Solution {
    int getOps(int x, int t){
        if((x & t) == t) return 0;
        int cur = 0;
        for(int i = 30; i >= 0; i--)  {
            int t1 = t & (1LL << i) , x1 = x & (1LL << i);
            if(t1 && !x1) {
                cur |= (1LL << i);
                cur |= (t & ((1LL << i) -1));
                return cur -x;
            }
            if(x1) cur |= (1LL << i);
        }
        return cur - x;
    }
public:
    int maximumAND(vector<int>& nums, int k, int m) {
        int cur = 0;
        for(int i = 30; i >= 0; i--) {
            int t = cur  | (1 << i);
            vector<int> cost;
            for(int x: nums) 
                cost.push_back(getOps(x, t));
            sort(begin(cost), end(cost));

            int need = 0;
            for(int i = 0; i < m; i++){
                need += cost[i];
                if(need > k) break;
            }
            if(need <=k) cur = t;
        }
        return (int) cur;
    }
};