class Solution {
public:
    string discountPrices(string s, int d) {
        istringstream iss(s);
        ostringstream oss;
        
        string str;
        while(iss >> str){
            if(str[0] != '$'){
                oss << str << " ";
                continue;
            }
            
            int sign = 0;
            for(int i = 1; i < str.size(); i++){
                char ch = str[i];
                if(ch < '0' || ch > '9'){
                    sign = 1;
                    break;
                }
            }
            
            if(sign == 1 || str.size() == 1){
                oss << str << " ";
                continue;
            }
            
            long long price = stoll(str.substr(1));
            double mod = price * 0.01 * (100 - d);
            oss << "$" << fixed << setprecision(2) << mod << " ";
        }
        
        string ans = oss.str();
        ans.pop_back();

        return ans;
    }
};