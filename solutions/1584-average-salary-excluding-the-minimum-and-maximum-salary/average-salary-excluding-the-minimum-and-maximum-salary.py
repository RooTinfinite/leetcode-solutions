class Solution:
    def average(self, salary: List[int]) -> float:
        salary.sort()
        sum = 0
        for s in salary:
            sum += s
        return (sum - salary[0] - salary[-1]) / (len(salary) - 2)