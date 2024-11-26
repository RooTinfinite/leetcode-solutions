class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        int n = s.size();
        string t = s.substr(1, n-2);
        int m = t.size();

        vector<string> v;
        for(int j = 0; j < m - 1; j++) {
            string s1 = t.substr(0, j+1), s2 =t.substr(j+1, m-1-j);
            vector<string> a, b;

            if(s1[0] != '0' || s1 == "0") a.push_back(s1);
            if(s2[0] != '0' || s2 == "0") b.push_back(s2);


            for(int k = 0; k < s1.size() - 1; k++) {
                bool flag = true;
                string sub1 = s1.substr(0, k+1), sub2 = s1.substr(k+1, s1.size() - 1 - k);

                for(int i = 0; i < sub2.size(); i++) {
                    if(sub2[i] != '0') flag = false;
                }
                if(flag || sub2[sub2.size() - 1] == '0') continue;

                string str = sub1 + "." + sub2;

                if(str[0] =='0' && str[1] != '.') continue;
                a.push_back(str);
            }

            for(int k = 0; k < s2.size() - 1; k++) {
                bool flag = true;
                string sub1 = s2.substr(0, k+1), sub2 =  s2.substr(k+1, s2.size() - 1 - k);

                for(int i = 0; i < sub2.size(); i++) {
                    if(sub2[i] != '0') flag = false;
                }
                if(flag || sub2[sub2.size() - 1] == '0') continue;

                string str = sub1 + "." + sub2;

                if(str[0] =='0' && str[1] != '.') continue;
                b.push_back(str);
            }
            
            for(int i = 0; i < a.size(); i++) {
                for(int k = 0; k < b.size(); k++) {
                    v.push_back("(" + a[i] + ", " + b[k] + ")");
                }
            }
        }
    
        return v;
    }
};