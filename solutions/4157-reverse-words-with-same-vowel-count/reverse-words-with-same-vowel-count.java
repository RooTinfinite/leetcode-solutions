class Solution {
    public int vowelcount(String str){
        String vowel="aeiou";
        int count=0;
        for(char ch:str.toCharArray()){
            if(vowel.indexOf(ch)!=-1){
                count++;
            }
        }
        return count;
    }
    public String reverseWords(String s) {
        String st[]=s.split(" ");
        int first=vowelcount(st[0]);
        for(int i=1;i<st.length;i++){
           if(vowelcount(st[i])==first){
               st[i]=new StringBuilder(st[i]).reverse().toString();
           }
        }
        return String.join(" ",st);
    }
}