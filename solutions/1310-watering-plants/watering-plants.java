class Solution {
    public int wateringPlants(int[] plants, int capacity) {
       int curr=capacity;
       int steps=0;
       for (int i=0;i<plants.length;i++){
       if(curr<plants[i]){
        steps+=2*i+1;
        curr=capacity-plants[i];
       }
       else
       {
        steps+=1;
        curr=curr-plants[i];
       }
       } 
       return steps;
    }
}