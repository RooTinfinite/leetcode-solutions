class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& a) {
        vector<Interval> res;
        map<int, int> timeline;
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a[i].size(); j++) {
                timeline[a[i][j].start]++;
                timeline[a[i][j].end]--;
            }
        }
        int workers = 0;
        for (pair<int, int> p : timeline) {
            workers += p.second;
            if (!workers) res.push_back(Interval(p.first, 0));
            if (workers && !res.empty() && !res.back().end) res.back().end = p.first;
        }
        if (!res.empty()) res.pop_back();
        return res;
    }
};