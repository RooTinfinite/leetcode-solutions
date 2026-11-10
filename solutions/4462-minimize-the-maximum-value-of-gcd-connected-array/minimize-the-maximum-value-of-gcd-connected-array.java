class Solution {
    public long minimumMaxValue(int n, int index, int value) {
         if(value==1){
             return -1;
         }
             int a=value;
        for(int i=2;1L*i*i<=value;i++){
            if(value%i==0){
                a=i;
                break;
            }
        }
        if(index>0){
             long left=value-a-2L*(index-1);
            if(left<=0) return -1;
        }
       long result=value;
        int right=n-1-index;
        if(right>0){
            result=value+a+2L*(right-1);
        }
        return result;
    }
}