pow2 = lambda x: pow(x,2)

class Solution:
    def minPartitionScore(self, nums: List[int], k: int) -> int:

        n = len(nums)
        pref = list(accumulate(nums, initial = 0))
        currDP = list(map(pow2, pref))
        
        for step in range(2, k + 1):
            prevDP, currDP, queue = currDP, [0] * (n + 1), deque()
            
            for i in range(step - 1, n):
                currM = -2 * pref[i]
                currC = prevDP[i] + pow2(pref[i]) 

                while len(queue) > 1:
                    (m2, c2), (m1, c1) = queue[-1], queue[-2] 
                    if (c2 - c1) * (m2 - currM) >= (currC - c2) * (m1 - m2): queue.pop()
                    else:  break
                queue.append((currM, currC))

                while len(queue) > 1:
                    (m1, c1), (m2, c2) = queue[0], queue[1]
                    if (m1 - m2) * pref[i + 1]  >= c2 - c1: 
                        queue.popleft()
                    else:
                        break

                currDP[(i+1)] = queue[0][0] * pref[i + 1] + queue[0][1] + pow2(pref[i + 1])

        return (currDP[n] + pref[n]) // 2