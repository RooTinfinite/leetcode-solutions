class RideSharingSystem {
public:
    vector<int>rider;
    vector<int>driver;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rider.push_back(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push_back(driverId);
        
    }
    
    vector<int> matchDriverWithRider() {
        if(rider.size()==0 || driver.size()==0)return {-1,-1};
        vector<int>ans={driver[0],rider[0]};
        driver.erase(driver.begin());
        rider.erase(rider.begin());
        return ans;
    }
    
    void cancelRider(int riderId) {
        auto it=find(rider.begin(),rider.end(),riderId);
        if(it!=rider.end())rider.erase(it);
    }
};
