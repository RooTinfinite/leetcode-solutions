class Solution {
public:
    int minTimeToType(string word) {
        int ans=word.size(); 
        int cur_ptr=1; 
        for(char c : word)
        {
            int pos=c-96; 
            int diff=abs(pos-cur_ptr); 
            ans+=min(diff,26-diff);
            cur_ptr=pos; 
        }
        return ans;
    }
};