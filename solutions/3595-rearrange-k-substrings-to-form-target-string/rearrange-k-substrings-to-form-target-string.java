class Solution {
    public boolean isPossibleToRearrange(String s, String t, int k) {
        int winSize = s.length()/k;
        int i = 0;
        int j = winSize;
        Map<String,Integer> map = new HashMap<>();
        while(j<=s.length()){
            String subStr = s.substring(i,j);
            map.put(subStr,map.getOrDefault(subStr,0)+1);
            i = j;
            j+=winSize;
        }
        i = 0;
        j = winSize;
        while(j<=t.length()){
            String subStr = t.substring(i,j);
            if(!map.containsKey(subStr) || map.getOrDefault(subStr,0) == 0) return false;
            map.put(subStr,map.get(subStr)-1);
            i = j;
            j+=winSize;
        }
        return true;
    }
}