class Solution {
public:
    static int equalSubstring(string& s, string& t, int maxCost) {
        const int n=s.size();
        int l=0, r;
        int cost=0, len=0;

        for (r = 0; r < n; r++) {
            cost+=abs(s[r]-t[r]);
            if (cost>maxCost) {
                cost-=abs(s[r]-t[r]);
                break;
            }
        }

        if (r==n && cost<=maxCost) return n;
        
        len=r; 

        for (; r<n; r++) {
            cost+=abs(s[r]-t[r]);
            while (cost > maxCost) {
                cost-=abs(s[l]-t[l]);
                l++;
            }
            len=max(len, r-l+1);
        }
        return len;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
