class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int res = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        // Try all combinations of one land ride and one water ride
        for (int i = 0; i < n; ++i) {
            int a = landStartTime[i]; // start time of land ride
            int d = landDuration[i];  // duration of land ride

            for (int j = 0; j < m; ++j) {
                int b = waterStartTime[j]; // start time of water ride
                int e = waterDuration[j];  // duration of water ride

                // Case 1: Do land ride first, then water ride
                int landEnd = a + d;
                int startWater = max(landEnd, b); // must wait if water hasn't started
                int finish1 = startWater + e;

                // Case 2: Do water ride first, then land ride
                int waterEnd = b + e;
                int startLand = max(waterEnd, a); // must wait if land hasn't started
                int finish2 = startLand + d;

                // Track minimum of both finish times
                res = min({res, finish1, finish2});
            }
        }

        return res;
    }
};