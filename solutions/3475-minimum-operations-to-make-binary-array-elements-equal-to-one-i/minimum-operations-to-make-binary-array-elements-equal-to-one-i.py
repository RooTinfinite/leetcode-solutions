class Solution:
    def minOperations(self, nums: List[int]) -> int:
        flip_queue = deque()  # Stores indices of flip operations
        count = 0  # Number of operations performed

        for i in range(len(nums)):
            # Remove expired flips (older than 3 indices)
            while flip_queue and i > flip_queue[0] + 2:
                flip_queue.popleft()

            # If the current element needs flipping
            if (nums[i] + len(flip_queue)) % 2 == 0:
                # Cannot flip a full triplet
                if i + 2 >= len(nums):
                    return -1
                count += 1
                flip_queue.append(i)

        return count