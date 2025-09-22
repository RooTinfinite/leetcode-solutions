class Solution {
    public int alternateDigitSum(int n) {
        int i=0,sum=0;
        while (n>0){
            if (i%2==0)
                sum+=n%10;
            else
                sum+=(n%10)*-1;
            i++;
            n/=10;
        }
        if (i%2==0) return sum*-1;
        return sum;
    }
}