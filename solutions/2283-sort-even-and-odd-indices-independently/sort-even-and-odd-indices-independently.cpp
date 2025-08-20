class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd , even ;
        for(int i = 0 ; i < nums.size() ; i++){
            if(i%2==0)
                even.push_back(nums[i]);
            else
                odd.push_back(nums[i]);
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end(), greater<int>());
        int e = 0 , s = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            if(i%2==0){
                nums[i] = even[e];
                e++;
            }
            else{
                nums[i] = odd[s];
                s++;
            }
        }
        return nums ;
    }
};