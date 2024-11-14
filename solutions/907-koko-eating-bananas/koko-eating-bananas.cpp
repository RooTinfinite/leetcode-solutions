class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=0,right=piles.size()-1,max=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]>max) max=piles[i];
        }
       
       
        int min=1,ans;
        while(min<=max){
            int mid=(min+max)/2;
            
            long int count=0;
            for(int i=0;i<piles.size();i++){
               count+=(piles[i] + mid - 1) / mid;
            }
            
             if(count<=h) max=mid-1;
            else min=mid+1;
        }
      return min;
    }
};