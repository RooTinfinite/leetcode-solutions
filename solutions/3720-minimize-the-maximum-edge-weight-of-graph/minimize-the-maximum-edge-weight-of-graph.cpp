class Solution {
public:
    vector<list<pair<int,int>>>graph;
    bool check(int mid){
        queue<int>qu;
        qu.push(0);
        unordered_set<int>vis;
        vis.insert(0);
        while(!qu.empty()){
            auto curr = qu.front();
            qu.pop();
            for(auto ngh:graph[curr]){
                if(ngh.second>mid or vis.count(ngh.first)==1) continue;
                qu.push(ngh.first);
                vis.insert(ngh.first);
            }
        }
        return vis.size()==graph.size();
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        graph.resize(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        int lo = 0;
        int hi = 1e6;
        int ans = INT_MAX;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(check(mid)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};