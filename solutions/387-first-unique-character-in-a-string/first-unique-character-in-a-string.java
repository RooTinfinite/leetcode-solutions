class Solution {
    public int firstUniqChar(String s) {
        ArrayList<Integer> firstUnique = new ArrayList<>();
        String letters = "abcdefghijklmnopqrstuvwxyz";
        
        for (char letter : letters.toCharArray()) {
            long count = s.chars().filter(ch -> ch == letter).count();
            if (count == 1) {
                firstUnique.add(s.indexOf(letter));
            }
        }
        
        return firstUnique.isEmpty() ? -1 : Collections.min(firstUnique);
    }
}