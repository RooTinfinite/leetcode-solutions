from scipy import optimize
import numpy

class Solution:
    def findMinimumTime(self, strength: List[int]) -> int:
        n = len(strength)
        costs = []
        for turn_energy in range(1, n + 1):
            turn_cost = []
            for s in strength:
                turn_cost.append(math.ceil(s/turn_energy))
            costs.append(turn_cost)
        costs = numpy.array(costs)
        return int(sum(costs[optimize.linear_sum_assignment(costs)]))