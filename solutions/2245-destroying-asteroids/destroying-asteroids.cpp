class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin() , asteroids.end());
        long long temp = mass;
        for (int i = 0 ; i < asteroids.size() ; i++) {
            if (asteroids[i] <= temp) temp += asteroids[i];
            else return false;
        }
        return true;
    }
};