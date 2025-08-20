class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        sum=0
        cost.sort(reverse=True)
        print(cost)
        for i in range(len(cost)):
            if (i+1)%3==0 and i!=0:
                pass
            else:
                sum=sum+cost[i]
        return sum