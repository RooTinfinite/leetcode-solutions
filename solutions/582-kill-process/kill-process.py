class Solution:
    def killProcess(self, pid: List[int], ppid: List[int], kill: int) -> List[int]:
        mapping = collections.defaultdict(list)
        for i in range(len(ppid)):
            mapping[ppid[i]].append(pid[i])

        queue = collections.deque()
        queue.append(kill)
        result = []
        while queue:
            killed = queue.popleft()
            result.append(killed)
            if killed in mapping:
                queue.extend(mapping[killed])

        return result