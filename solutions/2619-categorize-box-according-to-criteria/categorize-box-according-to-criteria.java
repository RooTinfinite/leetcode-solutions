class Solution {
    public String categorizeBox(int length, int width, int height, int mass) {
        if(isBulky(length,width,height) && mass >= 100)     return "Both";
        else if(!(isBulky(length,width,height)) && mass < 100)      return "Neither";
        else if(!(isBulky(length,width,height)) && mass >= 100)     return "Heavy";
        else    return "Bulky";
    
    }
    private static boolean isBulky(int length, int width, int height){
        long volume = (long)length * (long)width * (long)height;

        if(Math.max(length,Math.max(width,height)) >= 10_000)   return true;
        if( volume >= 1000_000_000) return true;
        return false;
    }
}