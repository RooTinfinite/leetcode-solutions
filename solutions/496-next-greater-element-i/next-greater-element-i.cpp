class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;  // Stack to keep track of elements for finding the next greater element
        unordered_map<int, int> mp;  // Hash map to store the next greater element for each number in nums2
        
        // Iterate through nums2 in reverse order to find the next greater elements
        for(int i = nums2.size() - 1; i >= 0; --i) {
            // Pop elements from the stack while the current element is greater than or equal to the top of the stack
            while(!st.empty() && nums2[i] >= st.top()) {
                st.pop();
            }

            // If stack is empty, there is no greater element; otherwise, the top of the stack is the next greater element
            mp[nums2[i]] = st.empty() ? -1 : st.top();
            
            // Push the current element onto the stack for future comparisons
            st.push(nums2[i]);
        }

        vector<int> result;  // Vector to store the final result

        // Iterate through nums1 and get the next greater element from the hash map
        for (int num : nums1) {
            result.push_back(mp[num]);
        }

        return result;  // Return the computed result
    }
};