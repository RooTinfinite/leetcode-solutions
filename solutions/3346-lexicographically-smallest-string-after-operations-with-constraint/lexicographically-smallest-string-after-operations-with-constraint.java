class Solution {
    public String getSmallestString(String s, int k) {
        StringBuilder sb = new StringBuilder("");
        int n = s.length();
        for(int i = 0; i < n; i++){
            char c = s.charAt(i);
            if(c == 'a')
                sb.append('a');
            else{
                int min = Math.min(c - 'a', ('z' - c) + 1);
                if(min <= k){
                    k -= min;
                    sb.append('a');
                }
                else{
                    int y = ((c - 'a') - k);
                    sb.append((char)(y + 'a'));
                    k = 0;
                }
            }
        }
        return sb.toString();
    }
}