class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> roman = new HashMap<>();
        roman.put('I', 1);
        roman.put('V', 5);
        roman.put('X', 10);
        roman.put('L', 50);
        roman.put('C', 100);
        roman.put('D', 500);
        roman.put('M', 1000);
        
        int n = s.length();
        int result = roman.get(s.charAt(n-1));
        
        for(int i = n-2; i >= 0; i--) {
            if(roman.get(s.charAt(i)) < roman.get(s.charAt(i+1))) {
                result -= roman.get(s.charAt(i));
            } else {
                result += roman.get(s.charAt(i));
            }
        }
        
        return result;
    }
}