class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
    if(n==1){
        return 0;
    }
        
        vector<bool>vis(n,false);
        int i=0;
        int j= (n+1)/2;
        while(i<=(n+1)/2){
            while(j<n && 2*arr[i]>arr[j]){
                j++;
            }
            if(j<n){
                vis[i]=1;
                vis[j]=1;
                ++i;
                j++;
            }
            if(i>=n || j>=n){
                break;
            }
            
        }
              int ans=0;
              for(int i=0;i<n;i++){
                  if(vis[i]){
                      ans++;
                  }
              }
        return ans;
        
    }
};