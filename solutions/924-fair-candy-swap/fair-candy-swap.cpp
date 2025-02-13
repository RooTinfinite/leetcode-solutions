class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA= accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sumB= accumulate(bobSizes.begin(), bobSizes.end(), 0);

        vector<int> ans;
        for(int i=aliceSizes.size()-1; i>=0; i--){
            for(int j=bobSizes.size()-1; j>=0; j--){
                if(sumA-(aliceSizes[i]-bobSizes[j]) == sumB+(aliceSizes[i]-bobSizes[j])){
                    ans.push_back(aliceSizes[i]);
                    ans.push_back(bobSizes[j]);
                    return ans;
                }
            }
        }
        return bobSizes;
    }
};