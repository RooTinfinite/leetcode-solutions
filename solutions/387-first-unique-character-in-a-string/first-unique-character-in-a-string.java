class Solution {
    public int firstUniqChar(String s) {
        int firstUnique = Integer.MAX_VALUE;
        
        for (char c = 'a'; c <= 'z'; c++) {
            int firstIndex = s.indexOf(c);
            if (firstIndex != -1 && firstIndex == s.lastIndexOf(c)) {
                firstUnique = Math.min(firstUnique, firstIndex);
            }
        }
        
        return firstUnique == Integer.MAX_VALUE ? -1 : firstUnique;
    }
}