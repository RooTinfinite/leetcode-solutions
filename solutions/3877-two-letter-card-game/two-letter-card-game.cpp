class Solution {
public:
    int score(vector<string>& cards, char x) {

        int ans = 0;
        int f = 0;
        int tf = 0;
        int s = 0;
        int ts = 0;
        int xx = 0;
        int used = 0;
        vector<int> dict1(26, 0);
        vector<int> dict2(26, 0);
        
        for (int i = 0; i < cards.size(); ++i) {

            char c1 = cards[i][0];
            char c2 = cards[i][1];

            if (c1 == x && c2 == x)
                xx++;
            else if (c1 == x) {

                dict1[c2 - 'a']++;
                f = max(dict1[c2 - 'a'], f);
                tf++;
                
            } else if (c2 == x) {

                dict2[c1 - 'a']++;
                s = max(dict2[c1 - 'a'], s);
                ts++;
            }
        
        }

        if (f > (tf - f)) {

            ans += (tf - f);
            tf = f - (tf - f);
            
        } else {

            ans += tf / 2;
            tf = tf % 2;
        }

        
        if (s > (ts - s)) {

            ans += (ts - s);
            ts = s - (ts - s);
            
        } else {

            ans += ts / 2;
            ts = ts % 2;
        }

        used += min(tf + ts, xx);
        xx -= min(tf + ts, xx);         
        ans = min(ans * 2, ans + xx / 2);
        ans += used;
        
        return ans;
    }
};