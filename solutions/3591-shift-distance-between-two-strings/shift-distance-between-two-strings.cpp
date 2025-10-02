class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        int n = s.length();
        long long res = 0;
        long long next[26] = {nextCost[0]}, prev[26] = {previousCost[0]};
        for (int i = 1; i < 26; i++){
            next[i] = (long long)nextCost[i] + next[i - 1];
            prev[i] = (long long)previousCost[i] + prev[i - 1];
        }
        for (int i = 0; i < n; i++){
            if (s[i] == t[i]) continue;
            int a = s[i] - 'a', b = t[i] - 'a';
            long long forward = 0, back = 0;
            if (b < a){
                forward += next[25] - (a != 0 ? next[a - 1] : 0); // forward
                if (b != 0) forward += next[b - 1];
                back = prev[a] - prev[b]; // back
            }
            else{
                forward += next[b - 1]; // forward
                if (a != 0) forward -= next[a - 1];
                back += prev[a] + prev[25] - prev[b]; // back
            }
            res += min(forward, back);
        }
        return res;
    }
};