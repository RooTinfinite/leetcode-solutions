class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            int digSum = 0;
            while(num > 0){
                int dig = num % 10;
                num /= 10;
                digSum += dig;
            }
            if(digSum == i) return i;
        }
        return -1;
    }
};