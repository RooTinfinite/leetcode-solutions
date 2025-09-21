class Solution: 
	def similarPairs(self, words: List[str]) -> int: 
		ans = 0
		freq = Counter()
		for word in words: 
			mask = reduce(or_, (1<<ord(ch)-97 for ch in word))
			ans += freq[mask]
			freq[mask] += 1
		return ans