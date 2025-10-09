class Solution {
    public int maxSubstrings(String word) {
        int[] last = new int[26];
        int n = word.length(), res = 0, mask = 0;
        for (int i = 0; i < n; i++){
            int c = word.charAt(i) - 'a';
            if ((mask & (1 << c)) == 0){
                last[c] = i;
                mask |= (1 << c);
            }
            else if (i - last[c] + 1 >= 4){
                res++;
                mask = 0;
            }
        }
        return res;
    }
}