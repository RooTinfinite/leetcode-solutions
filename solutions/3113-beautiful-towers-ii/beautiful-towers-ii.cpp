class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<int> nextSmallerLeft(n,-1) , nextSmallerRight(n,-1);
        stack<int> s1,s2;
        long long i;
        vector<long long> maxFromLeft(n) , maxFromRight(n);

        maxFromLeft[0] = maxHeights[0];
        s1.push(0);
        for(i=1;i<n;i++) {
            while(!s1.empty() && maxHeights[s1.top()] > maxHeights[i]) {
                s1.pop();
            }
            if( !s1.empty() ) {
                nextSmallerLeft[i] = s1.top();
            }
            s1.push(i);

            if( nextSmallerLeft[i] == -1 )
                maxFromLeft[i] = (i+1) * maxHeights[i];
            else
                maxFromLeft[i] = maxFromLeft[nextSmallerLeft[i]] + (maxHeights[i] * (i-nextSmallerLeft[i]));
        }        

        maxFromRight[n-1] = maxHeights[n-1];
        s2.push(n-1);
        for(i=n-2;i>=0;i--) {
            while(!s2.empty() && maxHeights[s2.top()] > maxHeights[i]) {
                s2.pop();
            }
            if( !s2.empty() ) {
                nextSmallerRight[i] = s2.top();
            }
            s2.push(i);

            if( nextSmallerRight[i] == -1 )
                maxFromRight[i] = (n - i) * maxHeights[i];
            else
                maxFromRight[i] = maxFromRight[nextSmallerRight[i]] + (maxHeights[i] * (nextSmallerRight[i]-i));
        }
        
        long long maxSum = 0;
        for(i=0;i<n;i++) {
            maxSum = max(maxSum , maxFromLeft[i] + maxFromRight[i] - maxHeights[i]);
        }
        return maxSum;
        
    }
};