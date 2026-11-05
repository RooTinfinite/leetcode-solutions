class Solution {
public:
    int minDeletions(vector<int>& a) {
        int n=a.size();
        int cnt=0;
        for(int i=0;i<n-1;i++){
            if((a[i]^a[i+1])==0){
                cnt++;
            }
            else{ continue; }
        }
        return cnt;
    }
};