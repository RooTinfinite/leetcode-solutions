class Solution {
    public boolean isSubstringPresent(String s) {
        String rev = "";
        for(char temp : s.toCharArray())    rev = temp + rev;
        
        for(int i=0;i<s.length()-1;i++){
            if(rev.contains(s.substring(i, i+2)))    return true;
        }
        return false;
    }
}