class Solution:
    def minProcessingTime(self, processorTime: List[int], tasks: List[int]) -> int:
        processorTime.sort()
        tasks.sort(reverse = True)
        a=[]
        j = 0
        for i in range(len(processorTime)):
            
            ans = processorTime[i]+tasks[j]
            a.append(ans)
            j = j+4
                
        return max(a)
                    
                
                
        