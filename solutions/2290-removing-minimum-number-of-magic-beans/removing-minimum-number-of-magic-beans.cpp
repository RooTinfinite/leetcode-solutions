class Solution {
public:
    long long minimumRemoval(vector<int>& a)
	{
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        long long mini = 99999999999999;
        long long totalBeans =0;
        for(auto bean : a)
        {
            totalBeans += (1LL)*bean;
        }
        long long n = 1LL*(int(a.size()));
        for(long long i=0;i<n;i++)
        {
            long long savedBeans = (1LL*a[i])*(1LL*(i+1));
            long long removedBeans = totalBeans - savedBeans;
            mini = min(mini , removedBeans);
        }
        return mini;
    }
};