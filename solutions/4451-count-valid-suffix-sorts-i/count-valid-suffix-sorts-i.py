class Solution:
    def update(self, freq, num, change):
        value = freq.get(num, 0) + change

        if value == 0:
            freq.pop(num, None)
        else:
            freq[num] = value

    def countSuffix(self, nums: List[int], target: List[int]) -> int:
        n = len(nums)
        ans = 0

        valid = [False] * (n + 1)
        valid[n] = True

        for i in range(n - 1, -1, -1):
            valid[i] = valid[i + 1]

            if i < n - 1 and target[i] < target[i + 1]:
                valid[i] = False

        freq = {}

        for i in range(n):
            self.update(freq, nums[i], 1)
            self.update(freq, target[i], -1)

        prefix = True

        for j in range(n):
            if prefix and valid[j] and not freq:
                ans += 1

            self.update(freq, nums[j], -1)
            self.update(freq, target[j], 1)

            if nums[j] != target[j]:
                prefix = False

        return ans