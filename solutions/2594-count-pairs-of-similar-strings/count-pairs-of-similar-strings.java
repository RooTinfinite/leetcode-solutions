class Solution {
	public int similarPairs(String[] words) {
		int ans = 0; 
		HashMap<Integer, Integer> freq = new HashMap(); 
		for (var word : words) {
			int mask = 0; 
			for (var ch : word.toCharArray()) 
				mask |= 1<<ch-'a'; 
			ans += freq.getOrDefault(mask, 0); 
			freq.merge(mask, 1, Integer::sum); 
		}
		return ans; 
	}
}