class Solution {
    public int maxBalancedShipments(int[] weight) {
        int high=0;
        int maxi=0;
        int shipments=0,n=weight.length;
        while(high<n){
            maxi=Math.max(maxi,weight[high]);
            if(weight[high]<maxi){
                maxi=0;
                shipments++;
            }
            high++;
        }
        return shipments;
    }
}