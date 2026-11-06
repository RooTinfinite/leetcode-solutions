class Solution {
    public int countMagicalPairs(String s) {
        int n = s.length();
        int res = 0;

        for(int i = 0; i < n; i++){
            boolean[] seen1 = new boolean[27];
            int[] l = new int[27];
            int[] r = new int[27];
            int ans1 = 0;

            for(int j = i; j >= 0; j--){
                int c = s.charAt(j) - 'a';

                if(seen1[c] == false){                
                    seen1[c] = true;
                    ans1++;
                }
                l[ans1]++;
            }

            boolean[] seen2 = new boolean[27];
            int ans2 = 0;
            
            for(int k = i + 1; k < n; k++){
                int c = s.charAt(k) - 'a';

                if(seen2[c] == false){
                    seen2[c] = true;
                    ans2++;
                }

                r[ans2]++;
            }

            for(int x = 1; x <= 26; x++){
                res += l[x] * r[x];
            }
        }
        return res;
    }
}