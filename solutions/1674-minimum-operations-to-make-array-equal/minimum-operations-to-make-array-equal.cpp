class Solution {
public:
    int minOperations(int n)
    {
        //brute force approach
        //time complexity: O(n)
        //space complexity: O(1)

        int i;
        int ans=0;

        //looping through 'odd indices'(1,3,5,7,.....)
        for(i=1;i<n;i=i+2)
        {
            //adding the difference between 'current-value' and 'target-value'
            ans=ans+(n-i);
        }    
        return ans;
    }
};