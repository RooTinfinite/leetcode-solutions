class Solution {
    public int passwordStrength(String password) {
        int point=0;
        HashSet<Character> set=new HashSet<>();
        for(char ch:password.toCharArray()){
            if(set.contains(ch)) continue;
            else{
                set.add(ch);
                if(ch>='a' && ch<='z')point+=1;
                else if(ch>='A' && ch<='Z')point+=2;
                else if(ch>='0' && ch<='9')point+=3;
                else point+=5;
            }
        }
        return point;
    }
}