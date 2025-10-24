class Solution {
    public int maxDistance(String[] words) {
        int n = words.length;
        int res = 0;

        for(int i = n - 1; i >= 0; i--) {
            if(!words[i].equals(words[0])) {
                res = Math.max(res, i + 1);     // farthest unique one.
                break;
            }
        }

        for(int i = 0; i <n; i++) {
            if(!words[i].equals(words[n - 1])) {
                res = Math.max(res, (n - 1 - i) + 1);
                break;
            }
        }

        return res;
    }
}