class Solution {
    public String addSpaces(String s, int[] spaces) {
        char[] ch=s.toCharArray();
        char[] charr=new char[s.length()+spaces.length];
        int idx=0,c=0;
        for (int sp:spaces){
            while (c<sp){
                charr[idx]=ch[c];
                idx++;
                c++;
            }
            charr[idx]=' ';
            idx++;
        }
        while(c<s.length()){
            charr[idx]=ch[c];
            idx++;
            c++;
        }
        return new String(charr);
    }

}