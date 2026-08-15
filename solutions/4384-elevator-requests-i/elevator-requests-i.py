class Solution:
    def elevatorRequests(self, n: int, requests: list[int]) -> int:
        total = 0
        curr = 0

        for floor in requests:

            total += abs(curr - floor)
            curr = floor

        return total