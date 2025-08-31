class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<pair<int,int>>> v(m,vector<pair<int,int>>(n)),u(m,vector<pair<int,int>>(n)),d(m,vector<pair<int,int>>(n)),l(m,vector<pair<int,int>>(n)),r(m,vector<pair<int,int>>(n));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int x=grid[i][j];
                v[i][j].first=0;
                v[i][j].second=0;
                while(x%2==0)
                {
                    x/=2;
                    v[i][j].first++;
                }
                while(x%5==0)
                {
                    x/=5;
                    v[i][j].second++;
                }
            }
        }
        u=v;
        d=v;
        l=v;
        r=v;
        
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                l[i][j].first+=l[i][j-1].first;
                l[i][j].second+=l[i][j-1].second;
                
                r[i][n-j-1].first+=r[i][n-j].first;
                r[i][n-j-1].second+=r[i][n-j].second;
            }            
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                u[j][i].first+=u[j-1][i].first;
                u[j][i].second+=u[j-1][i].second;
                
                d[m-j-1][i].first+=d[m-j][i].first;
                d[m-j-1][i].second+=d[m-j][i].second;
            }            
        }
        int res=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                int x1=u[i][j].first;
                int x2=u[i][j].second;
                int x3=l[i][j].first;
                int x4=l[i][j].second;
                
                int c2=x1+x3-v[i][j].first;
                int c5=x2+x4-v[i][j].second;
                res=max(res,min(c2,c5));
                //####################################
                x1=u[i][j].first;
                x2=u[i][j].second;
                x3=r[i][j].first;
                x4=r[i][j].second;
                
                c2=x1+x3-v[i][j].first;
                c5=x2+x4-v[i][j].second;
                res=max(res,min(c2,c5));
                
                //####################################
                x1=d[i][j].first;
                x2=d[i][j].second;
                x3=r[i][j].first;
                x4=r[i][j].second;
                
                c2=x1+x3-v[i][j].first;
                c5=x2+x4-v[i][j].second;
                res=max(res,min(c2,c5));
                //####################################
                x1=d[i][j].first;
                x2=d[i][j].second;
                x3=l[i][j].first;
                x4=l[i][j].second;
                
                c2=x1+x3-v[i][j].first;
                c5=x2+x4-v[i][j].second;
                res=max(res,min(c2,c5));
                
            }
        }
        return res;
        
    }
};