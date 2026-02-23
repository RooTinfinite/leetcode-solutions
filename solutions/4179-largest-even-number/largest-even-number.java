class Solution {
    public String largestEven(String s) {
        int i = s.lastIndexOf('2');
        return i == -1? "":s.substring(0,i+1);
    }
}