class Solution {
    public int numberOfSpecialChars(String word) {
        int n=word.length();
        Set<Character>lower=new HashSet<>();
        Set<Character>upper=new HashSet<>();
        for(char ch:word.toCharArray()){
           if(Character.isLowerCase(ch)){
             lower.add(ch);
           }
           else if(Character.isUpperCase(ch)){
            upper.add(ch);
           }
        }
        int count=0;
        for(char ch:lower){
            char ch1=Character.toUpperCase(ch);
              if(upper.contains(ch1)){
                count++;
              }
        }
        return count;
    }
}