class Solution {
    public int findMinimumOperations(String s1, String s2, String s3) {
        int i=0,j=0,k=0;
        int n1 = s1.length(),n2=s2.length(),n3=s3.length();
        for(;i<n1 && j<n2 && k<n3;i++,j++,k++){
            if(s1.charAt(i)==s2.charAt(j) && s2.charAt(j)==s3.charAt(k)){
                continue;
            }
            else break;
        }
        return i==0 ? -1 : (n1+n2+n3)-(i+j+k);
    }
}