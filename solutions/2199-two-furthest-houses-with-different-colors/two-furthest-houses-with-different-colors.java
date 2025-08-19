class Solution {
    public int maxDistance(int[] colors) {
        int min = 0;
        int right = colors.length -1;
        int max =0 ;
        

        for( int i=right; i>0 ;right--){
            if(colors[0] != colors[right]){
               max= Math.max(max, Math.abs(right - min));
               break;
            }
        }

        for (int j= 0; j< colors.length; j++){
             if(colors[j] != colors[colors.length -1]){
               max= Math.max(max, Math.abs( j - (colors.length -1) ) );
               break;
            }
        }

     return max;
    }
}