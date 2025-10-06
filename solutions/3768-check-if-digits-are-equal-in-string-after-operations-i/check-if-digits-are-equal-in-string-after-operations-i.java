class Solution {
    public boolean hasSameDigits(String s) {

        if(s.length() < 2){
            return true ;
        }

        while(s.length() != 2){
            StringBuilder ans = new StringBuilder();

            for(int i = 0 ; i < s.length() - 1 ; i++){

                int a = Character.valueOf(s.charAt(i));
                
                int b = Character.valueOf(s.charAt(i+1));

                int rem = (a + b) % 10 ;

                ans.append((char) rem);
            
            }

            s = ans.toString() ;
        }
        
        if(s.charAt(0) == s.charAt(1)){
            return true ;
        }

        return false ;
    }
}