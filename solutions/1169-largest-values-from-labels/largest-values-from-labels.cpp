class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {

        vector<vector<int>> arr;
        int n=values.size();
        for(int i=0;i<n;i++)
        {
            arr.push_back({values[i],labels[i]});
        }
        sort(arr.begin(),arr.end());
        unordered_map<int,int> mp;
        int score=0;
        for(int i=n-1;i>=0;i--)
        {
            if(numWanted>0&&mp[arr[i][1]]<useLimit)
            {
                mp[arr[i][1]]++;
                score+=arr[i][0];
                numWanted--;
            }
        }
        return score;
        
    }
};