class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        long long ans = 0;
        k = __gcd(k, (int)arr.size()); //re-evaluate k as the gcd of both k & arr.size
        
        for(int i = 0; i < k; ++i){
            vector<int> v;
            for(int j = i; j < arr.size(); j += k) v.push_back(arr[j]);  //collect each ith number
            sort(v.begin(), v.end());    //sort the collection to get median
            int mn = v[v.size()/2];      //get the median value
            for(int j = i; j < arr.size(); j += k) ans += abs(mn - arr[j]); // evaluate the ans by making all values equal to median
        }
        
        return ans;
    }
};