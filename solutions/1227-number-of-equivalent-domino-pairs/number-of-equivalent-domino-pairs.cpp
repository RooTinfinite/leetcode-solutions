class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        map<pair<int, int>, int> mp;
        int ans = 0;
        for (const auto &i : dominoes)
        {
            //checking in map and updating 'ans' variable
            if (i[0] < i[1])  ans += mp[{i[0], i[1]}];
            else  ans += mp[{i[1], i[0]}];
            
            //updation of map based on small value first and large value second
            if (i[0] < i[1])  ++mp[{i[0], i[1]}];
            else  ++mp[{i[1], i[0]}];
        }
        return ans;
    }
};