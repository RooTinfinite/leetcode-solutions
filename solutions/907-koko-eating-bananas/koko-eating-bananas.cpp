class Solution {
public:
    int getH(vector<int>& pile,int k){
        int h = 0;
        for (int i = 0; i < pile.size(); ++i) {
            h += pile[i]/k;
            if(pile[i]%k != 0)h++;
        }
        return h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int high = *max_element(piles.begin(), piles.end());
        int low = 1,mid;
        while(low<=high){
            mid = (high - low)/2 + low;
            if(getH(piles,mid) <= h && (mid == 1 || getH(piles,mid-1) > h)){
                return mid;
            }
            if(getH(piles,mid) > h){
                low = mid + 1;
            }else{
                high = mid - 1;
            }

        }
        return -1;

    }
};