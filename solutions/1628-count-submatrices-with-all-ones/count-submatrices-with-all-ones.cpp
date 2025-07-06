class Solution {
public:
    static int fun(vector<int>&v)
    {
        int length = 0;
        int ans = 0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i] == 0)
                length = 0;
            else
                length++;
            ans = ans + length;
        }
        return ans;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int sum = 0;
        for(int i=0;i<m;i++)
        {
            vector<int>v(n,1);
            for(int j=i;j<m;j++)
            {
                for(int k=0;k<n;k++)
                    v[k] = v[k]&mat[j][k];
                sum += fun(v);
            }
        }
        return sum;
    }
};