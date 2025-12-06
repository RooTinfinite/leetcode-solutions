class Solution {
public:
    long long maxPoints(vector<int>& a, vector<int>& b, int k) {
        long long ans = 0;
        int n = a.size();
        for(auto i: a) ans += i;

        vector<int>v;
        for(int i=0; i<n; i++) {
            v.push_back(b[i]-a[i]);
        }

        sort(v.begin(), v.end());
        cout<<ans<<endl;
        
        for(auto i: v) cout<<i<<' ';
        cout<<endl;
        
        for(int i=n-1; i>=k; i--) {
            if(v[i] <= 0)
                break;

            ans += v[i];
            // cout<<i<<'->'<<ans<<endl;
        }

        return ans;
    }
};