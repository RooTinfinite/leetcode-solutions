class Solution {
    public int maxGoodNumber(int[] nums) {
        String str1 = Integer.toBinaryString(nums[0]);
        String str2 = Integer.toBinaryString(nums[1]);
        String str3 = Integer.toBinaryString(nums[2]);
        
        int v1 = Integer.parseInt(str1+str2+str3, 2), v2 = Integer.parseInt(str1+str3+str2, 2);
        int v3 = Integer.parseInt(str2+str1+str3, 2), v4 = Integer.parseInt(str2+str3+str1, 2);
        int v5 = Integer.parseInt(str3+str1+str2, 2), v6 = Integer.parseInt(str3+str2+str1, 2);
        
        return Math.max( Math.max(Math.max(v1,v2), Math.max(v3,v4)), Math.max(v5,v6));
    }
}