class Solution:
    def subsequencesWithMiddleMode(self, nums: List[int]) -> int:
        p = 10 ** 9 + 7
        n = len(nums)

        # Variable meanings:
        # > leftCounter, rightCounter are Counters for numbers to the
        #       left and right of current index
        # > leftPairs, rightPairs store the number of non-equal pairs
        #       of numbers to the left and right of current index
        # > numSubsequences will store the final result
        leftCounter, rightCounter = Counter(), Counter(nums)
        leftPairs, rightPairs = 0, comb(n, 2) - sum([comb(val, 2) for val in rightCounter.values()])
        numSubsequences = 0

        for i, num in enumerate(nums): 
            # In this iteration, will consider subsequences  
            # whose unique mode is nums[i], or num

            # *** Part 1: bookkeeping rightCounter, rightPairs ***
            rightPairs -= (n - i - rightCounter[num])
            rightCounter[num] -= 1

            # The variable auxCount stores the number of subsequences
            # in which i is the middle index and num is a unique mode
            auxCount = 0 

            # *** Part 2: computing number of subsequences with exactly two instances of ***
            # ***         num, and no more than one instance of other numbers            ***

            # If num appears to the left of i:
            if leftCounter[num]: 
                for num2 in leftCounter:
                    # Consider values that appear to the left of i which are not equal to num
                    if num != num2 and leftCounter[num2] > 0:
                        # Start with the number of pairs of unequal numbers to the right of i
                        auxVal = rightPairs

                        # Subtract count of pairs to the right of i in which num appears
                        auxVal -= rightCounter[num] * (n - 1 - i - rightCounter[num])

                        # Subtract count of pairs to the right of i in which num2 appears
                        auxVal -= rightCounter[num2] * (n - 1 - i - rightCounter[num2])

                        # Add back count of pairs to the right of i in which both num and num2 appear
                        auxVal += rightCounter[num] * rightCounter[num2]

                        # Multiply by number of pairs to the left of i in which both num and num2 appear,
                        # and add to the total count of subsequences                    
                        auxCount += auxVal * leftCounter[num] * leftCounter[num2]

            # If num appears to the right of i:
            if rightCounter[num]: 
                for num2 in rightCounter:
                    # Consider values that appear to the right of i which are not equal to num 
                    if num != num2 and rightCounter[num2] > 0:
                        # Start with the number of pairs of unequal numbers to the left of i
                        auxVal = leftPairs

                        # Subtract count of pairs to the left of i in which num appears
                        auxVal -= leftCounter[num] * (i - leftCounter[num])
                        
                        # Subtract count of pairs to the left of i in which num2 appears 
                        auxVal -= leftCounter[num2] * (i - leftCounter[num2])
                        
                        # Add back count of pairs to the left of i in which both num and num2 appear
                        auxVal += leftCounter[num] * leftCounter[num2]
                        
                        # Multiply by number of pairs to the right of i in which both num and num2 appear,
                        # and add to the total count of subsequences
                        auxCount += auxVal * rightCounter[num] * rightCounter[num2]

            # *** Part 3: Computing number of subsequences with three or more occurrence of num ***
            # Sequences with two occurrences of num to the left of i and any number of occurrences of num to the right of i
            auxCount += comb(leftCounter[num], 2) * comb(n - 1 - i, 2)

            # Sequences with one occurrence of num to the left of i and at least one occurrence of num to the right of i
            auxCount += leftCounter[num] * (i - leftCounter[num]) * (comb(n - i - 1, 2) - comb(n - i - 1 - rightCounter[num], 2))

            # Sequences with no occurrences of num to the left of i and two occurrences of num to the right of i
            auxCount += comb(i - leftCounter[num], 2) * comb(rightCounter[num], 2)
            
            # *** Part 3: Add current count to overall result ***
            numSubsequences += auxCount
            
            # *** Part 4: bookkeeping leftCounter, leftPairs ***
            leftPairs += i - leftCounter[num]
            leftCounter[num] += 1
        
        return numSubsequences % p