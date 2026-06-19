class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini=INT_MAX;
        bool odd=false;
        for(auto t:nums1){
            
            if(t%2){
                odd=true;
                mini=min(mini,t);
            }
        }
        if(!odd) return true;
        for(int t:nums1){
            if(t%2==0 && mini>t) return false;
        }
        return true;
    }
};