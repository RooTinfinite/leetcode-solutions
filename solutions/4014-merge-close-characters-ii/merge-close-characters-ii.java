class Solution {
    public String mergeCharacters(String s, int k) {
        StringBuilder sb = new StringBuilder();
        int[] last = new int[26];
        Arrays.fill(last, -1);

        for(char c:s.toCharArray()){
            int index = c - 'a';
            int currentPos = sb.length();

            if(last[index]!=-1&&currentPos-last[index]<=k){
                continue;
            }
            last[index] = currentPos;
            sb.append(c);
        }

        return sb.toString();
    }
}