import java.util.*;

class Solution {
    public int getLeastFrequentDigit(int n) {
        String s = String.valueOf(n);
        int k = s.length();
        Map<Integer, Integer> freq = new HashMap<>();
        
        for(int i = 0; i < k; i++){
            int digit = s.charAt(i) - '0';
            freq.put(digit, freq.getOrDefault(digit, 0) + 1);
        }
        int minfreq = Integer.MAX_VALUE;
        for(Map.Entry<Integer, Integer> it : freq.entrySet()){
            minfreq = Math.min(minfreq, it.getValue());
        }
        int result = 10;
        for(Map.Entry<Integer, Integer> it : freq.entrySet()){
            if(it.getValue() == minfreq){
                result = Math.min(result, it.getKey());
            }
        }
        return result;
    }
}