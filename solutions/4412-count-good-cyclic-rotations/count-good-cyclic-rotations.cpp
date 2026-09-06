class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        /*
        Intuition 
        For every rotation, we only need the sum of its first n/2 elements

        Since the array is cyclic, these elements form a circular window of size n/2

        (while (j<n)) // But here while(i<n)

        If the sum of this window is greater than half of the total sum, then the first half is strictly greater than the second half..

        So we will be using sliding window over this circular array.

        Sum = (window) + (others) => others = sum - (window)
 
        window > others 

        window > sum - window

        window > (sum)/2
        */

        /*
        Approach

        Calculate the total sum of the array.

        Maintain a sliding window of size n/2.
        Use j%n to simulate the circular array (j=n   j%n = 0)

        When the window size reaches n/2 check whether 
        window > sum/2

        If yes then we increment the answer

        Remove the leftmost element and move the window forward.

        O(n)

        O(1)
        */


        long long sum = accumulate(nums.begin(),nums.end(),0LL);

        int n = nums.size();

        int half = n/2;

        long long curr = 0; //current sum of the sliding window

        int i = 0 , j = 0; //start and end
        int ans = 0;

        while(i<n){
            curr += nums[j%n];

            if(j-i+1 < half) j++;
            else if(j-i+1==half){
                if(curr > sum/2) ans++;

                curr -= nums[i];
                i++;
                j++;
            }
        }
        return ans;
    }
};