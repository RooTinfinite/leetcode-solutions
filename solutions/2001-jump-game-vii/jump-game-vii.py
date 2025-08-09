class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        q, max_reached = collections.deque([0]), 0
        while q:
            curr_i = q.popleft()
            if curr_i == len(s) - 1:
                return True
            start = max(curr_i + minJump, max_reached + 1)
            for i in range(start, min(curr_i + maxJump + 1, len(s))):
                if s[i] == '0':
                    q.append(i)
            max_reached = curr_i + maxJump
        return False