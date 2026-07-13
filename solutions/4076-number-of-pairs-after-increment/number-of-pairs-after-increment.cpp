
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {

        int n=nums2.size();

        vector<long long> nums(n);

        int block=sqrt(n);
        int sz=block;
        
        if(block*block<n)
           sz+=2;
       
        vector<unordered_map<long long,int>> help(sz);
        vector<long long> help2(sz,0);
        unordered_map<int,int>hash;

        for(int i=0;i<n;i++)
            {
                help[i/block][nums2[i]]++;
                nums[i]=nums2[i];
                hash[nums2[i]]++;
            }


        auto update=[&](int i,int j,int val)
        {
            if(j-i+1<=2*block)
            {
                while(i <=j )
                {
                    help[i/block][nums[i]]--;

                    help[i/block][nums[i]+val]++;
                    nums[i]=nums[i]+val;
                    i++;
                }
                return ;
                
            }
            while(i%block !=0 )
                {
                    help[i/block][nums[i]]--;
                    help[i/block][nums[i]+val]++;
                
                    nums[i]=nums[i]+val;
                    i++;
                }
            while(j%block != block-1)
                {
                    help[j/block][nums[j]]--;
                    help[j/block][nums[j]+val]++;

                    nums[j]=nums[j]+val;
                    j--;
                }
            while((i/block)<=(j/block))
                {
                    help2[i/block]+=val;
                    i+=block;
                }
            return ;
        };

        auto update2=[&](int i,int j,int val)
        {
            for(;i<=j;i++)
            {
                hash[nums[i]]--;
                nums[i]+=val;
                hash[nums[i]]++;
            }

        };
        auto queryAns=[&](int val){
            int ans=0;
            int i=0;
            while(i<sz)
                {
                    ans+=help[i][val-help2[i]];
                    i++;
                }
            return ans;
            
        };
        vector<int> ans;
        int cnt=0;
        bool flag=false;
        ans.reserve(queries.size());

        for(auto query:queries)
        if(query[0]==1)
        cnt++;

        if(cnt<=100)
        flag=true;

        for(auto &query:queries)
            {
                if(query[0]==1)
                {
                    int i=query[1],j=query[2],val=query[3];
                    cnt++;
                    if(flag)
                    update2(i,j,val);
                    else if(n>10)
                    update(i,j,val);
                    else{
                        while(i <=j )
                            {
                                help[i/block][nums[i]]--;
                               
                                help[i/block][nums[i]+val]++;
                                nums[i]=nums[i]+val;

                                i++;
                            }
                    }
                   
                }
                else{
                    int anscur=0;
                    for(auto num:nums1)
                        {
                           if(flag)
                             anscur+=hash[query[1]-num];
                            else anscur+=queryAns(query[1]-num);
                        }
                    ans.push_back(anscur);
                    
                }
                
            }
        return ans;
        
    }
};