class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int>ans;
        string p = to_string(n);
        for(int i=0;i<p.length();i++){
            string g = "";
            if(p[i]=='0') continue;
            g += p[i];
            for(int j=i+1;j<p.length();j++){
                g += '0';
            }
            ans.push_back(stoi(g));
        }
        return ans;
    }
};