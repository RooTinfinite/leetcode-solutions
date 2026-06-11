class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) 
    {
        vector<int> fr(101, 0);
        for(int& i:nums)
        {
            fr[i]++;
        }
        for(int i=0;i<=100;i++)
        {
            if(fr[i] == 0)
                continue;
            for(int j=i+1;j<=100;j++)
            {
                if(fr[j] != 0 && fr[i] != fr[j])
                    return {i,j};
            }
        }
        return {-1,-1};
    }
};