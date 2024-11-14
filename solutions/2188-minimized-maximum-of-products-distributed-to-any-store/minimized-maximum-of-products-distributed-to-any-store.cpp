class Solution {
private:
    bool canDistribute(vector<int>& quantities, int n, int x) {
        int stores = 0;
        for (int q : quantities) {
            stores += (q + x - 1) / x; 
        }
        return stores <= n;
    }
    
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = *max_element(quantities.begin(), quantities.end());
        int result = 0;
        
        while (left <= right) {
            int x = left + (right - left) / 2;
            
            if (canDistribute(quantities, n, x)) {
                result = x;
                right = x - 1;
            } else {
                left = x + 1;
            }
        }
        
        return result;
    }
};