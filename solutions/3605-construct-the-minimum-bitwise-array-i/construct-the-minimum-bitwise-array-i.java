
class Solution {
    public int[] minBitwiseArray(List<Integer> nums) {
        List<Integer> result = new ArrayList<>();
        for (int num : nums) {
            result.add(helper(num));}

        int[] arrayResult = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            arrayResult[i] = result.get(i);}
        
        return arrayResult;}

    private int helper(int num) {
        if (num % 4 == 1) {  // 4 mod 1 case
            return num - 1;
        }
        if (num % 4 == 3) {  // 4 mod 3 case
            int tmp = num;
            int i = 0;
            while (tmp > 0) {
                tmp /= 2;
                if (tmp % 2 == 0) break;
                i++;}

            return num - (1 << i);}
        return -1;  // just for num = 2
    }
}