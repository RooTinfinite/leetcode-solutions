class Solution {
    public int minimumCost(int m, int n, int[] a, int[] b) {
        int [][]arr=new int[m][n];
        int c[]=new int[m+n];
        for(int i=0;i<m-1;i++){
            c[i]=a[i];
        }
        for(int i=0;i<n-1;i++){
            c[i+m]=b[i];
        }
        int h=1,v=1;
        int ans=0,f=1;
        while(f==1){
            int max=0,idx=0;
            f=0;
            for(int i=0;i<m+n;i++){
                if(c[i]>max){
                    max=c[i];
                    idx=i;
                    f=1;
                }
            }
            if(idx<m){
                ans+=(v*max);
                h++;
            }
            else{
                ans+=(h*max);
                v++;
            }
            c[idx]=0;
        }
         return ans;
    }
}