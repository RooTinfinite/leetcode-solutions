class Solution {
    static List<Integer> palindromes = new ArrayList<>();
    static{
        for(int i = 1; i <= 5000; i++){
            if(isbinpalindrome(i)) palindromes.add(i);
        }
    }
    
    //binary palindrome pre compute
    private static boolean isbinpalindrome(int n){
        String s = Integer.toBinaryString(n);
        int l = 0, r = s.length() - 1;
        while (l < r){
            if (s.charAt(l++) != s.charAt(r--)) return false;
        }
        return true;
    }
    
    public int[] minOperations(int[] nums) {
        int[] result = new int[nums.length];
        for(int i = 0; i < nums.length; i++){
            result[i] = nearestpal(nums[i]);
        }
        return result;
    }

    private int nearestpal(int value){
        int left = 0, right = palindromes.size() - 1;
        int ans = Integer.MAX_VALUE;

        while (left <= right){
            int mid = left + (right - left) / 2;
            int curr = palindromes.get(mid);

            ans = Math.min(ans, Math.abs(curr - value));

            if (curr == value) return 0;
            else if (curr < value) left = mid + 1;
            else right = mid - 1;
        }

        return ans;
    }
}