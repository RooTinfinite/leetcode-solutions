class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        int min=10000,max=-10000;
        for(int i:arr){
            if(i<min)min=i;
            if(i>max)max=i;
        }
        int[] freq = new int[max-min+1];
        for(int i:arr){
            freq[i-min]++;
        }
        int[] occ = new int[arr.length+1];
        for(int i:freq){
            if(i!=0 && occ[i]>0){
                return false;
            }
            occ[i]++;
        }
        return true;
    }
}