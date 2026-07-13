class Solution:
    def minOperations(self, nums: list[int], k: int) -> int:
        evenFreq = [0] * k
        oddFreq  = [0] * k

        # group elements of nums by their remainder
        for i, num in enumerate(nums):
            if i & 1: oddFreq[num % k] += 1
            else: evenFreq[num % k] += 1

        evenCosts = self.buildCosts(evenFreq, k)
        oddCosts  = self.buildCosts(oddFreq, k)

        # ---------------------------------------------------
        #  x and y must be distinct
        # 
        #  Instead of looping through all combinations in O(k^2),
        #  get the two best y candidates and in case best y == best x,
        #  use the second best y. This yields O(k)
        # ---------------------------------------------------

        bestY = secondBestY = -1
        for rem in range(k):
            if bestY == -1 or oddCosts[rem] < oddCosts[bestY]:
                secondBestY = bestY
                bestY = rem
            elif secondBestY == -1 or oddCosts[rem] < oddCosts[secondBestY]:
                secondBestY = rem
                
        ans = math.inf
        for x in range(k):
            if x != bestY:
                ans = min(ans, evenCosts[x] + oddCosts[bestY])
            else:
                ans = min(ans, evenCosts[x] + oddCosts[secondBestY])

        return ans

    def buildCosts(self, freq: list[int], k: int) -> int:
        costs = [0] * k

        # ---------------------------------------------------
        #  STEP 1:
        #  Compute cost for target remainder = 0 to initialise DP
        # ---------------------------------------------------
        for remainder in range(k):
            distToTargetRem = min(remainder, k - remainder)
            costs[0] += freq[remainder] * distToTargetRem

        # ---------------------------------------------------
        #  Total number of elements in this parity group
        # ---------------------------------------------------
        totalElements = sum(freq)

        # ---------------------------------------------------
        #  STEP 2:
        #  Determine which remainders get CLOSER when
        #  target moves from 0 -> 1
        # 
        #  Those are:
        # 
        #  1, 2, 3, ..., floor(k/2)
        # ---------------------------------------------------
        halfCircle = k >> 1

        elementsGettingCloser = sum(freq[rem % k] for rem in range(1, halfCircle + 1))

        # ---------------------------------------------------
        #  STEP 3:
        #  Build all remaining costs using DP
        # ---------------------------------------------------

        for target in range(k - 1):

            unchangedElements = 0

            # ------------------------------------------------
            #  Special case when k is odd:
            # 
            #  One remainder is exactly opposite the target.
            # 
            #  Its distance does NOT change.
            # ------------------------------------------------
            if k & 1:
                oppositeRemainder = (target + halfCircle + 1) % k
                unchangedElements = freq[oppositeRemainder]

            # ------------------------------------------------
            #  Elements NOT getting closer must get farther
            # ------------------------------------------------
            elementsGettingFarther = totalElements - elementsGettingCloser - unchangedElements

            # ------------------------------------------------
            #  DP recurrence relation
            # ------------------------------------------------
            costs[target + 1] = costs[target] - elementsGettingCloser + elementsGettingFarther

            # ------------------------------------------------
            #  STEP 4:
            #  Slide the "closer" window forward
            # 
            #  target -> target + 1
            # 
            #  So update which remainders get closer next.
            # ------------------------------------------------

            leavingCloserRemSet = (target + 1) % k

            enteringCloserRemSet = (target + halfCircle + 1) % k

            elementsGettingCloser -= freq[leavingCloserRemSet]

            elementsGettingCloser += freq[enteringCloserRemSet]

        return costs