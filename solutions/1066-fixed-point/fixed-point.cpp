class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        // Initialize the boundary of search space
        int left = 0, right = arr.size() - 1;
        
        // Initialize answer to -1, 
        // If no answer is possible, we will return -1
        int answer = -1;
        
        // While the boundary size is non zero
        while (left <= right) {
            // The middle point in the search space
            // To divide the search space into two halves
            int mid = (left + right) / 2;
            
            if (arr[mid] == mid) {
                // Possible answer, 
                // But keep looking for smaller index on the left part
                answer = mid;
                right = mid - 1;
            } else if (arr[mid] < mid) {
                // No solution possible on left, move to the right half
                left = mid + 1;
            } else {
                // No solution possible on right, move to the left half
                right = mid - 1;
            }
        }
        
        return answer;
    }
};