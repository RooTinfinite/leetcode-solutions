class Solution {
public:
    
    int findKOr(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<32;i++){
            int c=0;
            for(int val : nums){
                if(val & (1<<i)) c++;
            }
            if(c >= k) sum += pow(2,i); // or we may write: sum += (1<<i);
        }
        return sum;
    }
};