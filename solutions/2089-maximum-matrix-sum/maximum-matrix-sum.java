class Solution {
    public long maxMatrixSum(int[][] matrix) {
        long s=0;
        int r=matrix.length;
        int c=matrix[0].length;
        int m=Integer.MAX_VALUE;
        boolean n=false;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int v=matrix[i][j];
                if(v<0){
                    n=!n;
                    v=-v;
                }
                s+=v;
                if (v<m){
                    m=v;
                }
            }
        }
        if(n)return s-m*2;
        return s;
    }
}