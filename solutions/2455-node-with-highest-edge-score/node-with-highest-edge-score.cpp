class Solution {
public:
    int edgeScore(vector<int>& edges) 
    {
        int n = edges.size();
        vector<long long>tmp(n,0);
        for(int i=0;i<n;i++)
            tmp[edges[i]] += i;
        long long ans = -1;
        int idx = 0;
        for(int i=0;i<n;i++)
        {
            if(tmp[i] > ans || (tmp[i] == ans && i < idx)) 
            {
                ans = tmp[i];
                idx = i;
            }
        }
        return idx;
    }
};