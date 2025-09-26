class Solution {
    public int minimumTimeToInitialState(String word, int k) {
        int count = 0;

        for (int i = 1; i <= word.length() / k; i++) {
            count = i;
            if (word.substring(k * i).equals(word.substring(0, word.length() - k * i))) {
                return i;
            }
        }

        return count + 1;        
    }
}