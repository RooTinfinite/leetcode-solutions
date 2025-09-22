class Solution {
	public static int minNumber(int[] nums1, int[] nums2) {

		Arrays.sort(nums1);
		Arrays.sort(nums2);


		for (int i = 0; i < nums1.length; i++) {
            for (int j = 0; j < nums2.length; j++) {
                if (nums1[i] == nums2[j]) {
                    return nums1[i];
                }
            }
        }

		int a  =  nums1[0];
		int b  =  nums2[0];


		if(a < b) {
			return Integer.parseInt(Integer.toString(a) + Integer.toString(b));

		}else {
			return Integer.parseInt(Integer.toString(b) + Integer.toString(a));
		}


	}
}