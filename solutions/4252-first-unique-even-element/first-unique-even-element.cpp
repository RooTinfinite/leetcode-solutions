class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int> hash;

        for(int num : nums){
            if(num % 2 == 0){
                hash[num]++;
            }
        }

        for(int num : nums){
            if(num % 2 == 0 && hash[num] == 1){
                return num;
            }
        }

        return -1;
    }
};