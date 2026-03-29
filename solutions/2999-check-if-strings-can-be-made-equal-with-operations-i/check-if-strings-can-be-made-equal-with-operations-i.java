class Solution {
    public boolean canBeEqual(String s1, String s2) {
        char[] ch1 = s1.toCharArray();
        char[] ch2 = s2.toCharArray();
        int i = 0;
        while(i < ch1.length){
            if(ch1[i] == ch2[i]){
                i++;
            }
            else{
                if(i+2 < ch1.length){
                    char temp = ch1[i];
                    ch1[i] = ch1[i+2];
                    ch1[i+2] = temp;
                }
                i++;
            }
        }
        for(int k=0;k<ch1.length;k++){
            if(ch1[k] != ch2[k]) return false;
        }
        return true;
    }
}