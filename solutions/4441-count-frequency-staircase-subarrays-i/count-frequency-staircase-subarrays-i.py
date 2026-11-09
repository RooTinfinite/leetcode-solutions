class Solution:
    def countStaircase(self, nums: list[int]) -> int:
        n = len(nums)
        ans = 0

        for i in range(n):
            first = {}
            freq = []
            invalid = 0

            for j in range(i, n):
                num = nums[j]

                if num not in first:
                    idx = len(freq)
                    first[num] = idx
                    freq.append(1)

                    if idx != 0:
                        invalid += 1
                else:
                    idx = first[num]
                    old = freq[idx]
                    expected = idx + 1
                    next = old + 1

                    if old != expected:
                        invalid -= 1

                    if next > expected:
                        break

                    freq[idx] = next

                    if next != expected:
                        invalid += 1

                if invalid == 0:
                    ans += 1

        return ans