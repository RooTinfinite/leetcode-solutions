class Solution {
public:
    vector<int> goodIndices(string s) {

        vector<int> ans;
        for (int i=0;i<s.length();++i) {

            if (i==0 && s[0]=='0') {
                ans.push_back(0);
                continue;
            }

            string goal = to_string(i);
            
            
            string t;

           

            for (int j=i;j>i-goal.length();--j) {
                t += s[j];
            }
            reverse(t.begin(), t.end());


            if (goal==t) ans.push_back(i);

        }
        return ans;
        
    }
};