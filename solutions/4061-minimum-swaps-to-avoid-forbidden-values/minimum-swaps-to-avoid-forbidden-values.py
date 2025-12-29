class Solution:
    def minSwaps(self, nums: list[int], forbidden: list[int]) -> int:
        n = len(nums)
        
        # 1. Feasibility Check
        nums_cnt = Counter(nums)
        forbidden_cnt = Counter(forbidden)
        
        for num, count in nums_cnt.items():
            blocked = forbidden_cnt[num]
            # If occurrences of 'num' + blocked spots for 'num' > total spots
            if count + blocked > n:
                return -1
        
        # 2. Count Conflicts and Find Majority Bad Element
        total_conflicts = 0
        bad_cnts = Counter()
        max_freq = 0
        
        for i in range(n):
            if nums[i] == forbidden[i]:
                total_conflicts += 1
                bad_cnts[nums[i]] += 1
                max_freq = max(max_freq, bad_cnts[nums[i]])
        
        if total_conflicts == 0:
            return 0
            
        # 3. Calculate Swaps
        # We can pair up at most (total // 2) or (total - max_freq) items
        pairs = min(total_conflicts // 2, total_conflicts - max_freq)
        
        return total_conflicts - pairs