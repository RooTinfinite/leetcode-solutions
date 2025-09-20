class Solution:
    def hardestWorker(self, n: int, logs: List[List[int]]) -> int:
        times = [logs[0][1]]
        max_time = times[0]
        for i in range(1, len(logs)):
            times.append(logs[i][1]-logs[i-1][1])
            max_time = max(max_time, times[i])
            
        id = 500     
        for i in range(len(times)):
            if times[i] == max_time:
                id = min(id, logs[i][0])
                
        return id