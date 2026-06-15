import java.util.*;

class Solution {
    public int firstUniqueEven(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();

        for(int num : nums){
            if(num % 2 == 0){
                map.put(num, map.getOrDefault(num, 0) + 1);
            }
        }

        for(int num : nums){
            if(num % 2 == 0 && map.get(num) == 1){
                return num;
            }
        }

        return -1;
    }
}