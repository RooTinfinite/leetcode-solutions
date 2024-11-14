class Solution {
private:
    int solveWithBinSearchByValue(int n, vector<int>& q) {
        sort(q.rbegin(), q.rend());
        
        int m = q.size();
        int left = 1;
        int right = q[0];
        int res = right;
        
        while (left <= right) {
            int freeSlots = n - m;
            int mid = (left + right) / 2;
            int i = 0;
            
            while (i < m && freeSlots >= 0) {
                int slots = (q[i] + mid - 1) / mid - 1;  // ceil(q[i]/mid) - 1
                if (!slots) {
                    break;
                }
                freeSlots -= slots;
                i++;
            }
            
            if (freeSlots < 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
                res = mid;
            }
        }
        
        return res;
    }
    
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        if (n == quantities.size()) {
            return *max_element(quantities.begin(), quantities.end());
        }
        
        return solveWithBinSearchByValue(n, quantities);
    }
};