class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int n = arr1.size(), m = arr2.size(), o = arr3.size();
        int i = 0, j = 0, k = 0;
        vector<int> ans;
        while(i<n && j<m && k<o) {
            if(arr1[i]==arr2[j] && arr2[j]==arr3[k]) {
                ans.push_back(arr1[i]);
            }
            int mini = min({arr1[i], arr2[j], arr3[k]});
            if(mini==arr1[i]) i++;
            if(mini==arr2[j]) j++;
            if(mini==arr3[k]) k++;
        }
        return ans;
    }
};