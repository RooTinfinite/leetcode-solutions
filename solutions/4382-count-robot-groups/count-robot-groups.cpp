#define ll long long
class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        ll groups = n;
        ll maxSpeed = speed[n - 1];

        for (int i = n - 1; i > 0; --i) {
            if (position[i] - position[i - 1] <= distance) {
                groups--;
            }
            else if (speed[i - 1] > maxSpeed) {
                groups--;
            }
            else {
                maxSpeed = speed[i - 1];
            }
        }

        return groups;
    }
};