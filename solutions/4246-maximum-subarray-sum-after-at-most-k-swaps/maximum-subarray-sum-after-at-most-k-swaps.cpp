class Solution {
public:
    #define f(i,j,n) for(int i=j;i<n;i++)
    #define sot(a) sort(a.begin(),a.end())

    struct seg{
        int size;
        vector<int>cnt,val;
        vector<long long>sum;

        void init(int n,vector<int>&v){
            size=n;
            val=v;
            cnt.assign(4*n,0);
            sum.assign(4*n,0);
        }

        void upd(int nd,int l,int r,int pos,int del){
            if(l==r){
                cnt[nd]+=del;
                sum[nd]+=1LL*del*val[pos];
                return;
            }

            int md=(l+r)/2;

            if(pos<=md) upd(2*nd,l,md,pos,del);
            else upd(2*nd+1,md+1,r,pos,del);

            cnt[nd]=cnt[2*nd]+cnt[2*nd+1];
            sum[nd]=sum[2*nd]+sum[2*nd+1];
        }

        void add(int pos){
            upd(1,0,size-1,pos,1);
        }

        void remove(int pos){
            upd(1,0,size-1,pos,-1);
        }

        int getsmallest(int nd,int l,int r,int k){
            if(l==r) return val[l];

            int md=(l+r)/2;

            if(k<=cnt[2*nd]) return getsmallest(2*nd,l,md,k);
            return getsmallest(2*nd+1,md+1,r,k-cnt[2*nd]);
        }

        int getlargest(int nd,int l,int r,int k){
            if(l==r) return val[l];

            int md=(l+r)/2;

            if(k<=cnt[2*nd+1]) return getlargest(2*nd+1,md+1,r,k);
            return getlargest(2*nd,l,md,k-cnt[2*nd+1]);
        }

        long long sums(int nd,int l,int r,int k){
            if(k<=0) return 0;
            if(cnt[nd]<=k) return sum[nd];
            if(l==r) return 1LL*k*val[l];

            int md=(l+r)/2;

            if(k<=cnt[2*nd]) return sums(2*nd,l,md,k);

            return sum[2*nd]+sums(2*nd+1,md+1,r,k-cnt[2*nd]);
        }

        long long suml(int nd,int l,int r,int k){
            if(k<=0) return 0;
            if(cnt[nd]<=k) return sum[nd];
            if(l==r) return 1LL*k*val[l];

            int md=(l+r)/2;

            if(k<=cnt[2*nd+1]) return suml(2*nd+1,md+1,r,k);

            return sum[2*nd+1]+suml(2*nd,l,md,k-cnt[2*nd+1]);
        }
    };

    long long maxSum(vector<int>& arr,int k) {
        int n=arr.size();


        vector<int>v=arr;
        sot(v);

        map<int,int>mp;
        int id=0;

        for(auto it:v){
            if(!mp.count(it)) mp[it]=id++;
        }

        vector<int>compressed(n);//coordinate compression
        f(i,0,n) compressed[i]=mp[arr[i]];

        int m=mp.size();

        vector<int>vals(m);
        for(auto it:mp) vals[it.second]=it.first;

        seg full;
        full.init(m,vals);
        //full seg tree
        f(i,0,n) full.add(compressed[i]);

        long long ans=-4e18;

        seg inner,outer;

        f(i,0,n){
            inner.init(m,vals);
            outer=full;
            //outer ->outside i->j subarray
            //inside means i.....j
            long long cur=0;

            f(j,i,n){
                outer.remove(compressed[j]);
                inner.add(compressed[j]);

                cur+=arr[j];

                int len=j-i+1;
                int mx=min(k,min(len,n-len));
                //binary seaarch to find optiml no of swaps
                //swaps x =min(k,len of inner,len of outer) x->upto which bhar ka xth largest > andar ka xth smallest tbtk swap kr skte
                int lo=1,hi=mx,y=0;

                while(lo<=hi){
                    int md=(lo+hi)/2;

                    int a=inner.getsmallest(1,0,m-1,md);
                    int b=outer.getlargest(1,0,m-1,md);

                    if(b>a){
                        y=md;
                        lo=md+1;
                    }
                    else hi=md-1;
                }

                long long now=cur;

                if(y){// sum add kia 
                    now+=outer.suml(1,0,m-1,y);
                    now-=inner.sums(1,0,m-1,y);
                }

                ans=max(ans,now);
            }
        }

        return ans;
    }
};