class Solution {
public:
        vector<int> bestCoordinate(vector<vector<int>>& t, int radius) {
        
            sort( begin(t), end(t) );
        
            deque<int> reach_x;
            int tid = 0, max_x = 0, max_y = 0, max_q = 0;
       
        for (int x = t.front()[0]; x <= t.back()[0]; ++x) 
        {
            while (tid < t.size() && x + radius >= t[tid][0]) reach_x.push_back(tid++);
            
            while (!reach_x.empty() && t[reach_x.front()][0]+radius < x) reach_x.pop_front();
            
            for (int y = 0; y <= 50; ++y) 
            {
                int q = 0;
                for (auto id : reach_x) {
                    if (t[id][1] < y - radius || t[id][1] > y + radius)
                        continue;
                    auto dd = (t[id][0] - x) * (t[id][0] - x) + (t[id][1] - y) * (t[id][1] - y);
                    if (dd <= radius * radius)
                        q += t[id][2] / (1 + sqrt(dd));
                }
                if (max_q < q) 
                {
                    max_q = q; max_x = x; max_y = y; 
                }
            }
        }

        return {max_x, max_y};
    }
};