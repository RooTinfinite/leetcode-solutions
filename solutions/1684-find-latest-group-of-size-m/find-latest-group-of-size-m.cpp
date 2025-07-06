class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        if(n==m)
        return n;
        vector<int>length(n+2,0);
        vector<int>count(n+1,0);
        int ans = -1;
        for(int i=0; i<n; i++)
        {
            int a = arr[i], low = length[a-1], high = length[a+1];
            int sum = low + high + 1;
            length[a-low] = length[a+high] = sum;
            count[low]--;
            count[high]--;
            count[sum]++;
            if(count[m]>0)
            ans= i+1;
        }
        return ans;
    }
};