class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int> m1, m2;
        
        for (auto i : nums1) m1[i] ++;
        for (auto i : nums2) m2[i] ++;
        
        int only_in_1 = 0;
        int only_in_2 = 0;
        int both = 0;
        
        for (auto i : m1) 
            if (m2.find(i.first) != m2.end()) both ++;
            else only_in_1 ++;
        
        for (auto i : m2) 
            if (m1.find(i.first) == m1.end()) only_in_2 ++;
        
        only_in_1 = min (only_in_1, n/2);
        only_in_2 = min (only_in_2, n/2);
        
        if (only_in_1 < n/2) {
            int req = n/2 - only_in_1;
            int has = min (req, both);
            
            both -= has;
            only_in_1 += has;
        }
        if (only_in_2 < n/2) {
            int req = n/2 - only_in_2;
            int has = min (req, both);
            
            both -= has;
            only_in_2 += has;
        }
        
        return (only_in_1 + only_in_2);
    }
};