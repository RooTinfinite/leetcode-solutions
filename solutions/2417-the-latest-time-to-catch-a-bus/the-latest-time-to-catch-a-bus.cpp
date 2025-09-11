class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        
        vector<int> latest(passengers.size());

        latest[0] = passengers[0]-1;
        for(int i=1; i<passengers.size(); i++){
            if(passengers[i] != passengers[i-1]+1){
                latest[i] = passengers[i]-1;
            } else {
                latest[i] = latest[i-1];
            }
        }
        
        int ans = latest[0];
        int j=0;
        for(int i=0; i<buses.size(); i++){
            int k = upper_bound(passengers.begin()+j, passengers.end(), buses[i]) - passengers.begin() - 1;
            k = min(k, j+capacity-1);
            if(k == -1){
                ans = buses[i];
            } else if(k-j+1 < capacity && passengers[k] != buses[i]){
                ans = buses[i];
            } else {
                ans = latest[k];
            }
            j = k+1;
        }

        return ans;
    }
};