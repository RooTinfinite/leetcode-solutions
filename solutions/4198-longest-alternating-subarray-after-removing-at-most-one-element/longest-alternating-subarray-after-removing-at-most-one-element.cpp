class Solution {
public:
    int longestAlternating(vector<int>& a) {
        int n = a.size();
        vector<int> b(n);
        int maxi = 1;
        for(int i=0;i<n-1;i++){
            if(a[i]<a[i+1] || a[i]>a[i+1]){
                maxi = max(maxi,2);
            }
            if(a[i]==a[i+1]){
                if(i-1>=0 && i+2<n && a[i]>a[i-1] && a[i]>a[i+2]){
                    maxi=3;
                }
                if(i-1>=0 && i+2<n && a[i]<a[i-1] && a[i]<a[i+2]){
                    maxi=3;
                }
            }
        }
        vector<int> pre(n),suff(n);
        for(int i=1;i<n-1;i++){
            if(a[i]>a[i-1] && a[i]>a[i+1]){
                pre[i] = 1;
                suff[i] = 1;
                b[i] = 1;
                maxi=3;
            }
            if(a[i]<a[i-1] && a[i]<a[i+1]){
                pre[i] = 1;
                suff[i] = 1;
                b[i] = -1;
                maxi=3;
            }
        }
        int cnt = 1;
        for(int i=1;i<n-1;i++){
            if((b[i]==1 && b[i+1]==-1) || (b[i]==-1 && b[i+1]==1)){
                cnt++;
                pre[i+1] = cnt;
                //cout<<i<<" "<<pre[i]<<endl;
                maxi = max(maxi,cnt+2);
            }
            else{
                cnt = 1;
            }
        }
        cnt=1;
        for(int i=n-2;i>0;i--){
            if((b[i]==1 && b[i-1]==-1) || (b[i]==-1 && b[i-1]==1)){
                cnt++;
                suff[i-1] = cnt;
                maxi = max(maxi,cnt+2);
            }
            else{
                cnt = 1;
            }
        }

        for(int i=1;i<n-1;i++){
            if(b[i]==0){
                if(b[i-1]==1 && b[i+1]==-1){
                    if(a[i-1]>a[i+1] && a[i-1]>a[i-2] && a[i+1]<a[i-1] && a[i+1]<a[i+2]){
                        maxi = max(maxi, suff[i+1]+pre[i-1]+2);
                    }
                }
                if(b[i-1]==-1 && b[i+1]==1){
                    if(a[i-1]<a[i+1] && a[i-1]<a[i-2] && a[i+1]>a[i-1] && a[i+1]>a[i+2]){
                        maxi = max(maxi, suff[i+1]+pre[i-1]+2);
                    }
                }
                if(i+2<n && b[i-1]==1 && a[i-1]>a[i+1] && a[i+1]<a[i-1] && a[i+1]<a[i+2]){
                    maxi = max(maxi, pre[i-1]+suff[i+2]+1+2);
                }
                if(i+2<n && b[i-1]==-1 && a[i-1]<a[i+1] && a[i+1]>a[i-1] && a[i+1]>a[i+2]){
                    maxi = max(maxi, pre[i-1]+suff[i+2]+1+2);
                }
                if(i-2>=0 && b[i+1]==1 && a[i+1]>a[i-1] && a[i-1]<a[i+1] && a[i-1]<a[i-2]){
                    maxi = max(maxi, suff[i+1]+pre[i-2]+1+2);
                }
                if(i-2>=0 && b[i+1]==-1 && a[i+1]<a[i-1] && a[i-1]>a[i+1] && a[i-1]>a[i-2]){
                    maxi = max(maxi, suff[i+1]+pre[i-2]+1+2);
                }
            }
        }

        return maxi;
    }
};