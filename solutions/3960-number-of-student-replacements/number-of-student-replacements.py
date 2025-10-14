class Solution:
  def totalReplacements(self, ranks: List[int]) -> int:
    min_v, res = ranks[0], 0
    for i in range(1, len(ranks)):
      if ranks[i] < min_v:
        min_v = ranks[i]
        res += 1
    return res
      