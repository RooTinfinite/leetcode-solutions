class Solution {
    public long interchangeableRectangles(int[][] rectangles) {
        double[] ratio = new double[rectangles.length];
        int i=0;
        for(int [] arr:rectangles){
            ratio[i] = (double)arr[0]/arr[1];
            i++;
        }
        long ans = 0;
        Arrays.sort(ratio);
        double ch = ratio[0];
        int cc = 1;
        for(int j=1;j<ratio.length;j++){
            if(ch == ratio[j]){
                ans +=(long)cc;
                cc+=1;
            }
            else{
                ch = ratio[j];
                cc = 1;
            }
        }
        return ans;
    }
}