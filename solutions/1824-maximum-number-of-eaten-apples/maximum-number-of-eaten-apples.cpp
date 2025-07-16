class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        vector<int> applesExpiry(n + 20001, 0);
        int count = 0;
        int lastDay = n;
        int latestExpiryPointer = 0;

        for (int currentDay = 0; currentDay < lastDay; currentDay++) {
            // calculate the expiry of apples received on currentDay and update
            // map
            if (currentDay < n) {
                int currentExpiry = days[currentDay] + currentDay;
                applesExpiry[currentExpiry] += apples[currentDay];
                if (currentExpiry < latestExpiryPointer)
                    latestExpiryPointer = currentExpiry;
                // update last day if current expiry is greater
                if (currentExpiry > lastDay) lastDay = currentExpiry;
            }
            while ((latestExpiryPointer <= currentDay ||
                    applesExpiry[latestExpiryPointer] == 0) &&
                   latestExpiryPointer < lastDay) {
                latestExpiryPointer++;
            }
            // eat an apple on current day
            if (applesExpiry[latestExpiryPointer] != 0) {
                applesExpiry[latestExpiryPointer]--;
                count++;
            }
        }
        return count;
    }
};