class Solution {
public:
    long long minOperations(vector<int>& nums, int k) {
        vector<long long> evenFreq(k, 0), oddFreq(k, 0);

        // group elements of nums by their remainder
        for (int i = 0; i < nums.size(); ++i) {
            if (i & 1) oddFreq[nums[i] % k]++;
            else evenFreq[nums[i] % k]++;
        }

        vector<long long> evenCosts = buildCosts(evenFreq, k);
        vector<long long> oddCosts  = buildCosts(oddFreq, k);

        //---------------------------------------------------
        // x and y must be distinct
        //
        // Instead of looping through all combinations in O(k^2),
        // get the two best y candidates and in case best y == best x,
        // use the second best y. This yields O(k)
        //---------------------------------------------------
        int bestY = -1, secondBestY = -1;
        for (int rem = 0; rem < k; ++rem) {
            if (bestY == -1 || oddCosts[rem] < oddCosts[bestY]) {
                secondBestY = bestY;
                bestY = rem;
            } else if (secondBestY == -1 || oddCosts[rem] < oddCosts[secondBestY]) {
                secondBestY = rem;
            }
        }

        long long ans = LLONG_MAX;
        for (int x = 0; x < k; ++x) {
            if (x != bestY)
                ans = min(ans, evenCosts[x] + oddCosts[bestY]);
            else
                ans = min(ans, evenCosts[x] + oddCosts[secondBestY]);
        }

        return ans;
    }

private:
    vector<long long> buildCosts(const vector<long long>& freq, int k) {

        vector<long long> costs(k, 0);

        //---------------------------------------------------
        // STEP 1:
        // Compute cost for target remainder = 0 to initialise DP
        //---------------------------------------------------
        for (int remainder = 0; remainder < k; ++remainder) {
            int distToTargetRem = min(remainder, k - remainder);
            costs[0] += freq[remainder] * distToTargetRem;
        }

        //---------------------------------------------------
        // Total number of elements in this parity group
        //---------------------------------------------------

        long long totalElements = 0;
        for (long long count : freq)
            totalElements += count;

        //---------------------------------------------------
        // STEP 2:
        // Determine which remainders get CLOSER when
        // target moves from 0 -> 1
        //
        // Those are:
        //
        // 1, 2, 3, ..., floor(k/2)
        //---------------------------------------------------

        int halfCircle = k >> 1;

        long long elementsGettingCloser = 0;
        for (int remainder = 1; remainder <= halfCircle; ++remainder)
            elementsGettingCloser += freq[remainder % k];

        //---------------------------------------------------
        // STEP 3:
        // Build all remaining costs using DP
        //---------------------------------------------------

        for (int target = 0; target < k - 1; ++target) {

            long long unchangedElements = 0;

            //------------------------------------------------
            // Special case when k is odd:
            //
            // One remainder is exactly opposite the target.
            //
            // Its distance does NOT change.
            //------------------------------------------------
            if (k % 2 == 1) {
                int oppositeRemainder = (target + halfCircle + 1) % k;
                unchangedElements = freq[oppositeRemainder];
            }

            //------------------------------------------------
            // Elements NOT getting closer must get farther
            //------------------------------------------------

            long long elementsGettingFarther = totalElements
                                               - elementsGettingCloser
                                               - unchangedElements;

            //------------------------------------------------
            // DP recurrence relation
            //------------------------------------------------

            costs[target + 1] = costs[target]
                                - elementsGettingCloser
                                + elementsGettingFarther;

            //------------------------------------------------
            // STEP 4:
            // Slide the "closer" window forward
            //
            // target -> target + 1
            //
            // So update which remainders get closer next.
            //------------------------------------------------

            int leavingCloserRemSet = (target + 1) % k;

            int enteringCloserRemSet = (target + halfCircle + 1) % k;

            elementsGettingCloser -= freq[leavingCloserRemSet];

            elementsGettingCloser += freq[enteringCloserRemSet];
        }

        return costs;
    }
};