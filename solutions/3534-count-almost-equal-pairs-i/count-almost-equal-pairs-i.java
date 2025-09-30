class Solution {
    public int countPairs(int[] nums) {

		int count=0;
		for(int i=0;i<nums.length-1;i++) {
			for(int j=i+1;j<nums.length;j++) {
				
				if(areAlmostEqual(nums[i], nums[j])) {
					 count++;
				}
			}
		}
		return count;
    }

	 public boolean areAlmostEqual(Integer a, Integer b) {
		 
		 if (a==b) {
			 return true;
		 }
		 
		 String s1 = a+"";
		 String s2 = b+"";
		 
		 if(s1.length()< s2.length()) {
			 s1 = String.format("%0" + s2.length() + "d", a);
		 }else if(s1.length()> s2.length()) {
			 s2 = String.format("%0" + s1.length() + "d", b);
		 }
		 
		 int mismatchCount=0;
		 int n = s1.length();
		 char c1=0,c2=0;
		 for(int i=0;i<n;i++) {
			 
			 if(s1.charAt(i)!=s2.charAt(i)) {
				 if(mismatchCount==0) {
					 c1=s1.charAt(i);
					 c2=s2.charAt(i);
				 }else if(mismatchCount==1) {
					 if(c1!=s2.charAt(i) || c2!=s1.charAt(i)) {
						 break;
					 }
				 }
				 mismatchCount++;
				 if(mismatchCount>2) {
					 break;
				 }
			 }
		 }
		 
		 return mismatchCount == 0 || mismatchCount==2;
		 
	 }

}
