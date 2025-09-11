class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        
        unordered_map<int,int> hm;     //****store index of element in map
        for(int i =0;i<nums.size();i++){
            
            hm[nums[i]] = i;   //** use map to find the index 
        }
        
        for(int i =0;i<operations.size();i++){
            
            
            int a  = operations[i][0];
            int b = operations[i][1];
            
            nums[hm[a]] = b;
            
            hm[b] = hm[a];  //**also store the changed element in hashmap
            
            
        }
        return nums;
        
    }
};