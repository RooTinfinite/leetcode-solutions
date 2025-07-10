class Solution {
public:
    void solve(priority_queue<pair<int,int>> &pq,pair<int,int> &a,pair<int,int> &b){
              if(!pq.empty()){
            a=pq.top();
            pq.pop();
            if(!pq.empty()){
                b=pq.top();
                pq.pop();
            }
        }
    }
    int minimumOperations(vector<int>& nums) {
        int i,n=nums.size(),ans=INT_MAX,ro=(n+1)/2,re=n-ro;
        map<int,int> even,odd;
        for(i=0;i<n;i++){
            if(i%2==0) even[nums[i]]++;
            else odd[nums[i]]++;
        }
        priority_queue<pair<int,int>> pqeven,pqodd;
        for(auto &it: even){
          pqeven.push({it.second,it.first});
        }
        for(auto &it: odd){
            pqodd.push({it.second,it.first});
        }

        pair<int,int> even1={0,-1},even2={0,-1};
        solve(pqeven,even1,even2);

        pair<int,int> odd1={0,-1},odd2={0,-1};
        solve(pqodd,odd1,odd2);

        if(even1.second!=odd1.second){
            ans=min(ans,(re-even1.first)+(ro-odd1.first));
        }
        else{
            int op1=(re-even1.first)+(ro-odd2.first);
            int op2=(re-even2.first)+(ro-odd1.first);
            ans=min(ans,min(op1,op2));
        }

      return ans;
    }
};