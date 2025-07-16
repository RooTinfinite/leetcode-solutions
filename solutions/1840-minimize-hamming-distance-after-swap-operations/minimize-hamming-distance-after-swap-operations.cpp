class DisjointSet
{
    public:
    vector<int>rank,parent,size;

    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
           
        }

    }

    int findParent(int node)
    {
        if(node==parent[node])
        {
            return node;
        }

        return parent[node]=findParent(parent[node]);

    }

    void UnionByRank(int u,int v)
    {
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);

        if(ulp_u==ulp_v)
        {
            return;
        }

        if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
        }

        else if(rank[ulp_u]>rank[ulp_v])
        {
            parent[ulp_v]=ulp_u;
        }

        else
        {
            parent[ulp_v]=ulp_u;
            rank[ulp_v]++;

        }

    }

    
};
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) 
    {
        int n=source.size();
        
        DisjointSet ds(n);

        for(auto it:allowedSwaps)
        {
            ds.UnionByRank(it[0],it[1]); // We are making connected component
        }
        
        unordered_map<int,unordered_map<int,int>>mp;

        
        for(int i=0;i<source.size();i++)
        {
            mp[ds.findParent(i)][source[i]]++;

// for each ultimate parent we are storing all other members of that component
        }
        int hamming=n;
        
        for(int i=0;i<n;i++)
        {
            
            
               unordered_map<int,int>& freq=mp[ds.parent[i]];
                
               if(freq.find(target[i])==freq.end())
               {
                   continue;
                   
               }
            
            else
            {
                hamming--;
                freq[target[i]]--;
                if(freq[target[i]]==0)
                {
                    freq.erase(target[i]);
                }
            }
            
            
            
            
            
        }
        
        return hamming;
        
        
        

        
    }
};