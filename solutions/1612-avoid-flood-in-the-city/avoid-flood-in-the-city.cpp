class Solution {
public:
   vector<int> avoidFlood(vector<int> &r)
{
    vector<int> a;
    unordered_map<int, int> mp;
    for (int i = 0; i < r.size(); i++)
    {
        if (r[i] == 0)
        {
            a.push_back(i);
            r[i] = 1;
        }
        else
        {
            if (mp.count(r[i]))
            {
                auto it = upper_bound(a.begin(), a.end(), mp[r[i]]);
                if (it == a.end())
                    return {};
                r[*it] = r[i];
                a.erase(it);
            }
            mp[r[i]] = i;
            r[i] = -1;
        }
    }
    return r;
}
};