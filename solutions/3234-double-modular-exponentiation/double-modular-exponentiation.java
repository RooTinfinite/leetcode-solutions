class Solution {
    
    public static int power(int a , int b , int m){
        int x =a;
        int ans =1;
        while(b!=0){
            if(b%2 == 1){
                ans = (ans *x) %m ;
            }
            x = (x*x)%m;
            b/=2;
        }
        return ans;
    }
    
    public List<Integer> getGoodIndices(int[][] variables, int target) {
        List<Integer> list = new ArrayList<>();
        for(int i=0;i<variables.length;i++){
            long res =0;
            int a = variables[i][0];
            int b = variables[i][1];
            int c = variables[i][2];
            int d = variables[i][3];
            res = (long)power(power(a,b ,10),c,d);
            if( (int)res== target)
                list.add(i);
            }
        return list;
        }
}