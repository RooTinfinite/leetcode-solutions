class Solution {
	public static int semiOrderedPermutation(int[] nums) {

		int n = nums.length;

		int pos1 =  0;
		int posn =  0;

		for (int i = 0; i < n; i++) {
			if(nums[i] == 1) {
				pos1 = i;
			}
			if(nums[i] == n) {
				posn = i;
			}
		}


		if(pos1 < posn) {
			return  pos1 + (n - 1 - posn);
		}

		else {
			return pos1 + (n - 1 - posn) - 1;
		}

	}
}