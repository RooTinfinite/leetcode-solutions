class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int , long long> last;
        long long res = 0;
        for(int i = 0, n = tasks.size(); i < n; ++i){
            int type = tasks[i];
            if(last.count(type)) res = max(res , last[type] + space);
            last[type] = ++res;
        }
        return res;
    }
};