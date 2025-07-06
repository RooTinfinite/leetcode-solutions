class Solution {
public:
    string rotate(string s ,int b) {
        int n = s.size();
        b = b % n;

        reverse(s.begin() ,s.end());
        reverse(s.begin() ,s.begin() + (n - b));
        reverse(s.begin() + (n - b) ,s.end());

        return s;
    }

    string add(string s ,int a) {
        int n = s.size();

        for(int i=0 ;i<n ;i++) {
            if(i%2 == 0) continue;

            int num = s[i] - '0';
            num += a;
            
            s[i] = (num % 10) + '0';
        }
        return s;
    }

    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> sett;
        sett.insert(s);

        queue<string> q;
        q.push(s);

        string ans(s.size() ,'9');
        while(!q.empty()) {
            auto currStr = q.front();
            q.pop();
            
            if(currStr < ans) ans = currStr;

            string rotatedStr = rotate(currStr ,b);
            if(!sett.count(rotatedStr)) {
                sett.insert(rotatedStr);
                q.push(rotatedStr);
            }

            string addedStr = add(currStr ,a);
            if(!sett.count(addedStr)) {
                sett.insert(addedStr);
                q.push(addedStr);
            }
        }
        return ans;
    }
};