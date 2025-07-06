class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int count = 0;
        
        unordered_map<long long, int> productMap1;
        unordered_map<long long, int> productMap2;
        
        // Type 1: nums1[i]^2 = nums2[j] * nums2[k]
        for (int j = 0; j < nums2.size(); ++j) {
            for (int k = j + 1; k < nums2.size(); ++k) {
                productMap1[(long long)nums2[j] * nums2[k]]++;
            }
        }
        
        for (int i = 0; i < nums1.size(); ++i) {
            long long target = (long long)nums1[i] * nums1[i];
            if (productMap1.find(target) != productMap1.end()) {
                count += productMap1[target];
            }
        }
        
        // Type 2: nums2[i]^2 = nums1[j] * nums1[k]
        for (int j = 0; j < nums1.size(); ++j) {
            for (int k = j + 1; k < nums1.size(); ++k) {
                productMap2[(long long)nums1[j] * nums1[k]]++;
            }
        }
        
        for (int i = 0; i < nums2.size(); ++i) {
            long long target = (long long)nums2[i] * nums2[i];
            if (productMap2.find(target) != productMap2.end()) {
                count += productMap2[target];
            }
        }
        
        return count;
    }
};