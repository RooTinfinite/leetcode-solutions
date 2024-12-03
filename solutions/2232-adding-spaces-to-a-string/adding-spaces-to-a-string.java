class Solution {
    public String addSpaces(String s, int[] spaces) {
        char[] result = new char[s.length() + spaces.length];
        int writePos = 0;
        int readPos = 0;
        
        for (int spacePos : spaces) {
            while (readPos < spacePos) {
                result[writePos++] = s.charAt(readPos++);
            }
            result[writePos++] = ' ';
        }
        
        while (readPos < s.length()) {
            result[writePos++] = s.charAt(readPos++);
        }
        
        return new String(result);
    }
}