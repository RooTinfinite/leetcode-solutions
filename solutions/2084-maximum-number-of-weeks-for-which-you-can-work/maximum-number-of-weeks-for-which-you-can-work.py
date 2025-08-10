class Solution:
    def numberOfWeeks(self, milestones: List[int]) -> int:
        _sum, _max = sum(milestones), max(milestones)
		# (_sum - _max) is the sum of milestones from (2) the rest of projects, if True, we can form another project with the same amount of milestones as (1)
		# can refer to the section `Why the greedy strategy works?` for the proof
        if _sum - _max >= _max:  
            return _sum
        return 2 * (_sum - _max) + 1  # start from the project with most milestones (_sum - _max + 1) and work on the the rest of milestones (_sum - _max)