class Solution:
    def delayedCount(self, nums: List[int], k: int) -> List[int]:
      indexes = defaultdict(list)

      for i in range(len(nums)):
        indexes[nums[i]].append(i)

      result = []
      for i in range(len(nums)):
        if len(indexes[nums[i]]) == 1:
          result.append(0)
          continue

        pos = bisect.bisect_right(indexes[nums[i]], i+k)
        result.append(len(indexes[nums[i]]) - pos)

      return result      
        