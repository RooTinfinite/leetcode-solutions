class Solution:
    def bestClosingTime(self, customers: str) -> int:
        curPenalty = sum(c == "Y" for c in customers)

        # Start with closing at hour 0, the penalty equals all 'Y' in closed hours.
        minPenalty = curPenalty
        earliestHour = 0

        for i, ch in enumerate(customers):
            # If status in hour i is 'Y', moving it to open hours decrement
            # penalty by 1. Otherwise, moving 'N' to open hours increment
            # penalty by 1.
            if ch == "Y":
                curPenalty -= 1
            else:
                curPenalty += 1

            # Update earliestHour if a smaller penalty is encountered.
            if curPenalty < minPenalty:
                earliestHour = i + 1
                minPenalty = curPenalty

        return earliestHour