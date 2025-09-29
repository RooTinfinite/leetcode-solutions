class Solution {
    public int minimumChairs(String s) {
        int n=s.length();
        int count=0,max=0;
        for(int i=0;i<n;i++){
            if(s.charAt(i)=='E'){
                count++;
            }
            else{
                count--;
            }
            max=Math.max(count,max);
        }
        return max;
    }
}