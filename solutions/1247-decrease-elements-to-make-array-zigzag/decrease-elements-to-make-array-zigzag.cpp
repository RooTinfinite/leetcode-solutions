class Solution {
public:
	int movesToMakeZigzag(vector<int>& nums) {
		int cnt1 = 0, cnt2 = 0;

		if (nums.size() <= 1) return 0;

		// make odd indices smaller
		for (int i = 1; i < nums.size(); i += 2) {
			if (i == nums.size() - 1) {
				if (nums[i - 1] <= nums[i]) cnt1 += nums[i] - nums[i - 1] + 1;
			} else {
				if (nums[i - 1] <= nums[i] || nums[i + 1] <= nums[i]) {
					cnt1 += nums[i] - min(nums[i - 1], nums[i + 1]) + 1;
				}
			}
		}

		// make even indices smaller
		for (int i = 0; i < nums.size(); i+= 2) {
			if (i == 0) {
				if (nums[i] >= nums[i + 1]) cnt2 += nums[i] - nums[i + 1] + 1;
			} else if (i == nums.size() - 1) {
				if (nums[i - 1] <= nums[i]) cnt2 += nums[i] - nums[i - 1] + 1;
			} else {
				if (nums[i - 1] <= nums[i] || nums[i + 1] <= nums[i]) {
					cnt2 += nums[i] - min(nums[i - 1], nums[i + 1]) + 1;
				}
			}
		}


		return min(cnt1, cnt2);

	}
};