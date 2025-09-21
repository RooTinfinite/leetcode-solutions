class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = INT_MIN;
        for(auto str : strs){
            bool flag = true;
            int n = str.size();
            for(auto x : str){
                if(!isdigit(x)){
                    flag = false;
                    break;
                }
            }
            if(flag)
            ans = max(ans , stoi(str));
            else
            ans = max(ans , n);
        }
        return ans;
    }
};