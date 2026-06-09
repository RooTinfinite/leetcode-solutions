class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int>ans;
        vector<bool>currentBulbStatus(101,false);
        for(int i=0;i<bulbs.size();i++){
            int currentBulbToBeToggeled=bulbs[i];
            currentBulbStatus[currentBulbToBeToggeled]
                          =!currentBulbStatus[currentBulbToBeToggeled];
        }
        for(int i=1;i<=100;i++){
            if(currentBulbStatus[i]==true)ans.push_back(i);
        }
        return ans;
    }
};