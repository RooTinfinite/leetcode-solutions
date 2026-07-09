class Solution {
public:
    int n, P;
    vector<int> seg, arr;

    int gcdv(int a,int b){
        if(!a) return b;
        if(!b) return a;
        return gcd(a,b);
    }

    void build(int i,int l,int r){
        if(l==r){
            seg[i] = (arr[l]%P==0 ? arr[l]/P : 0);
            return;
        }

        int m=(l+r)/2;

        build(i*2,l,m);
        build(i*2+1,m+1,r);

        seg[i]=gcdv(seg[i*2],seg[i*2+1]);
    }

    void update(int i,int l,int r,int idx,int val){
        if(l==r){
            seg[i]=(val%P==0 ? val/P : 0);
            return;
        }

        int m=(l+r)/2;

        if(idx<=m) update(i*2,l,m,idx,val);
        else update(i*2+1,m+1,r,idx,val);

        seg[i]=gcdv(seg[i*2],seg[i*2+1]);
    }

    bool canExcludeOne(int i,int l,int r,int ext){
        if(l==r) return ext==1;

        int m=(l+r)/2;

        int left  = gcdv(ext, seg[i*2+1]);
        int right = gcdv(ext, seg[i*2]);

        if(left==1 || right==1) return true;

        return canExcludeOne(i*2,l,m,left) ||
               canExcludeOne(i*2+1,m+1,r,right);
    }

    int countGoodSubseq(vector<int>& nums, int p, vector<vector<int>>& queries) {

        arr = nums;
        P = p;
        n = arr.size();

        seg.assign(4*n,0);

        int cnt = 0;
        for(int x:arr) if(x%P==0) cnt++;

        build(1,0,n-1);

        int ans=0;

        for(auto &q:queries){
            int idx=q[0], val=q[1];

            if(arr[idx]%P==0) cnt--;
            if(val%P==0) cnt++;

            arr[idx]=val;

            update(1,0,n-1,idx,val);

            if(seg[1]==1){
                if(cnt<n) ans++;
                else if(canExcludeOne(1,0,n-1,0)) ans++;
            }
        }

        return ans;
    }
};