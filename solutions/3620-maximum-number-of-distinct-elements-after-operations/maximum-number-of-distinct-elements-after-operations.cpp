class Solution {
public:
    int maxDistinctElements(vector<int>& arr,int diff){
        int prev=INT_MIN;
        set<int>c;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            int x = max(prev + 1, arr[i]-diff);
            
            if (x<=arr[i]+diff){
                c.insert(x);
                prev = x;
            }
        }
        return c.size();
    }
};