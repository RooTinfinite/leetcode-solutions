class Solution:
    def employeeFreeTime(self, schedule: '[[Interval]]') -> '[Interval]':
        
		# Flatten the given intervals.
        ints = []
        for i in schedule:
            [ints.append(x) for x in i]
        
		# Sort the intervals by starting time which is a key part of this soln. and indentifying overlap.
        ints.sort(key = lambda x:x.start)
        
		# Now we want to merge intervals (the continuous periods of being busy).
        merged = []
        for i in ints:
		    # If we have no intervals in our list or the current task starts after the previous one ends.
            if not merged or i.start > merged[-1].end:
                merged.append(i)
            else:
			    # We know that the start time intersects the start,end of the previous task, so we take the max ending time.
				# As this will be a merged, continuous busy period.
                merged[-1].end = max(i.end, merged[-1].end)

        # Now we have our merged intervals we can look at the time between the merged 
		# intervals as these will be the free time for the employee. 
        free = []
        for i in range(1, len(merged)):
            free.append(Interval(start=merged[i-1].end, end=merged[i].start))
			
		# Now we're left with intervals of free time.
        return free