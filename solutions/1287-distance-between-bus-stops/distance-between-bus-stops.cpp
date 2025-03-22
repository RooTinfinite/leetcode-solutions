class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int total=0,sum=0;
        if(start>destination){
            swap(start,destination);
        }
        for(int i=start;i<destination;i++){
            sum += distance[i];
        }
        for(int i=0;i<distance.size();i++){
            total += distance[i];
        }
        int cirsum=total-sum;
        return min(cirsum,sum);
    }
};