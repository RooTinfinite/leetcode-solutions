
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
       sort(arr.begin(), arr.end());
        int n = arr.size();
        int median = arr[(n - 1) / 2];
        int left = 0;
        int right = n - 1;
        vector<int>result;
        for(int i=0; i<k; i++){// we only need k elements 
            if (abs(arr[right] - median) >= abs(arr[left] - median)) {// if both are equal we need to select the higher one ,if greater select right as defualt
                // right will be always higher (bcoz we already sorted)
                result.push_back(arr[right]);
                right--;
            }else{
                result.push_back(arr[left]);
                left++;
            }
        }
        
        return result;
    }
};