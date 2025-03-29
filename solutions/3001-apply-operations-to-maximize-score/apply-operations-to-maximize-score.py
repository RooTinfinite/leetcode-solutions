class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        # Algorithms: Monotonic Stack, Heap (Priority Queue), and Greedy
        # We calculate a "prime score" for each number, use a monotonic stack
        # to determine left and right boundaries for dominant subarrays,
        # and then applie a greedy strategy with a priority queue (min-heap)
        # to maximize the score.

        MOD = 10**9 + 7
        N = len(nums)
        res = 1

        # 1. Calculate prime scores for each number in nums.
        prime_scores = []
        for n in nums:
            score = 0
            for f in range(2, int(sqrt(n)) + 1):
                if n % f == 0:
                    score += 1
                    while n % f == 0:
                        n = n // f
            if n >= 2:
                score += 1
            prime_scores.append(score)

        # 2. Use a Monotonic Stack to find left and right bounds for each number.
        left_bound = [-1] * N
        right_bound = [N] * N

        stack = []

        for i, s in enumerate(prime_scores):
            while stack and prime_scores[stack[-1]] < s:
                index = stack.pop()
                right_bound[index] = i
            if stack:
                left_bound[i] = stack[-1]
            stack.append(i)

        # 3. Use a Heap (Priority Queue) to process numbers in decreasing order.
        min_heap = [(-n, i) for i, n in enumerate(nums)]  # num, index
        heapify(min_heap)

        # 4. Apply operations greedily to maximize the score.
        while k > 0:
            n, index = heappop(min_heap)
            n = -n
            score = prime_scores[index]

            left_cnt = index - left_bound[index]
            right_cnt = right_bound[index] - index

            count = left_cnt * right_cnt
            operations = min(count, k)
            res = (res * pow(n, operations, MOD)) % MOD
            k -= operations

        return res