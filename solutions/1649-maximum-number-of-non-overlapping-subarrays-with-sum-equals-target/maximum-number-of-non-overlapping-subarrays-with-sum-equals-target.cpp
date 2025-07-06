class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        
        unordered_map<int, int> mpp;
        vector<vector<int>> intervals;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==target){
                vector<int> ds(2);
                ds[0] = 0;
                ds[1] = i;
                intervals.push_back(ds);
            }
            if(mpp.find(sum-target)!=mpp.end()){
                vector<int> ds(2);
                ds[0] = mpp[sum-target]+1;
                ds[1] = i;
                intervals.push_back(ds);
            }
            mpp[sum] = i;
        }
        for(auto it : intervals){
            cout<<it[0]<<"--"<<it[1]<<endl;
        }
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int left = 0, right=1, count = 0;
        while(right<n){
            if(intervals[left][1]<intervals[right][0]){
                left = right;
                right++;
            }
            else if(intervals[left][1]<intervals[right][1]){
                right++;
                count++;
            }
            else if(intervals[left][1]>=intervals[right][1]){
                left = right;
                count++;
                right++;
            }
        }
        return intervals.size() - count;
    }
};