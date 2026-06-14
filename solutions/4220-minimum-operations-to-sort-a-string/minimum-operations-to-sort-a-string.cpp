class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string s1 = s;
        string s2 = s;
        sort(s1.begin(),s1.begin() + n-1);
        sort(s2.begin()+1,s2.end());
        if(is_sorted(s.begin(), s.end())) return 0;
        if(is_sorted(s1.begin(), s1.end()) || is_sorted(s2.begin(), s2.end())) return 1;

        if(s1[n-1] >= s1[0]) return 2;
        if(s2[0] <= s2[n-1]) return 2;
        if(n>2) return 3;
        return -1;
    }
};