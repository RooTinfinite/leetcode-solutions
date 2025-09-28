#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int n, d=0;
    bool test(string& s, int len){
        int k=n/len;
        array<int, 26> freq0, freq1;
        freq1.fill(0);
        for(int i=0; i<len; i++) 
            freq1[s[i]-'a']++;
        for(int i=1; i<k; i++){
            freq0.fill(0);
            for(int j=len*i; j<len*(i+1) ; j++)
                freq0[s[j]-'a']++;
            if (freq0!=freq1) return 0;
            freq1=freq0;
        }
        return 1;
    }

    int minAnagramLength(string& s) {
        n=s.size();
        if (n==1) return 1;
        int freq[26]={0};
        for(char c: s) freq[c-'a']++;
        for(int x: freq) 
            if (x!=0) d=gcd(d, x);
        if (d==1) return n;
        vector<int> divisor={1, d};
        double sqrt_d=sqrt(d);
        for(int i=2; i<sqrt_d; i++){
            auto [q, r]=div(d, i);
            if (r==0) {
                divisor.push_back(i);
                divisor.push_back(q);
            }
        }
        if (sqrt_d!=(int)(sqrt_d)) divisor.push_back(d/sqrt_d); 
        divisor.push_back(sqrt_d);
        sort(divisor.begin(), divisor.end());
        for(int dd: divisor){
            int len=n/d*dd;
            if (test(s, len)) return len;
        }
        return n;
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();