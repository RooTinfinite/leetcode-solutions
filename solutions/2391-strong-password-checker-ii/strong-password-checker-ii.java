class Solution {
    public boolean strongPasswordCheckerII(String password) {
        boolean low=false;
        boolean up=false;
        boolean digit=false;
        boolean sc=false;
        boolean st=true;
        int len=password.length();
        if(len<8) return false;
        for(int i=0;i<len;i++){
            char c=password.charAt(i);
            if((int)c>96 && (int)c<123) low=true;
            if((int)c>64 && (int)c<91) up=true;
            if(c>='0' && c<='9') digit=true;
            if(i<len-1 ){
                char d=password.charAt(i+1);
                if(c==d) st=false;
            }
            if("!@#$%^&*()-+".indexOf(c)!=-1)sc=true;            
        }

      if(sc&& up&& low && st&& digit) return true;
        return false;
    }
}