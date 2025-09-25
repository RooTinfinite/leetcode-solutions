class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        int prev=-1;
        vector<int>ans;
        list<int>li;
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=-1){
                li.push_front(nums[i]);
            }
            else{
                if(prev==-1||prev+1==i){
                    k++;
                    if(k>li.size()){
                        ans.push_back(-1);
                    }
                    else{
                        list<int>:: iterator it =li.begin();
                        advance(it,k-1);
                        ans.push_back(*it);
                    }
                    prev=i;
                }
                else{
                    k=1;
                    list<int>::iterator it =li.begin();
                    advance(it,k-1);
                    ans.push_back(*it);
                    prev=i;
                }
            }
        }
        return ans;
    }
};